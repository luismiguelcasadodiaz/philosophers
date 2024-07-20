/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pag_364.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:11:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/20 12:10:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <bsd/err.h>
/* ************************************************************************** */
/* realizamos la sincronización de processos independientes, detachables, con */
/* una variable global.                                                       */
/* ************************************************************************** */

volatile int g_hilos;

static void	pthread_display_attr(pthread_attr_t *attr, char *prefix)
{
	int					s;
	int					i;
	size_t				v;
	void				*stkaddr;
	struct sched_param	sp;

	s = pthread_attr_getdetachstate(attr, &i);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getdetachstate");
	printf("___________________ INIT_ATTR_DUMP___________________\n");
	if (i == PTHREAD_CREATE_DETACHED)
		printf("%sDetach state     =(%d) PTHREAD_CREATE_DETACHED\n", prefix, i);
	if (i == PTHREAD_CREATE_JOINABLE)
		printf("%sDetach state     =(%d) PTHREAD_CREATE_JOINABLE\n", prefix, i);
	s = pthread_attr_getscope(attr, &i);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getscope");
	if (i == PTHREAD_SCOPE_SYSTEM)
		printf("%sScope            =(%d) PTHREAD_SCOPE_SYSTEM\n", prefix, i);
	if (i == PTHREAD_SCOPE_PROCESS)
		printf("%sScope            =(%d) PTHREAD_SCOPE_PROCESS\n", prefix, i);
	s = pthread_attr_getinheritsched(attr, &i);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getinheritsched");
	if (i == PTHREAD_INHERIT_SCHED)
		printf("%sInherit scheduler=(%d) PTHREAD_INHERIT_SCHED\n", prefix, i);
	if (i == PTHREAD_EXPLICIT_SCHED)
		printf("%sInherit scheduler=(%d) PTHREAD_EXPLICIT_SCHED\n", prefix, i);
	s = pthread_attr_getschedpolicy(attr, &i);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getschedpolicy");
	if (i == SCHED_OTHER)
		printf("%sScheduling policy=(%d) SCHED_OTHER\n", prefix, i);
	if (i == SCHED_FIFO)
		printf("%sScheduling policy=(%d) SCHED_FIFO\n", prefix, i);
	if (i == SCHED_RR)
		printf("%sScheduling policy=(%d) SCHED_RR\n", prefix, i);
	s = pthread_attr_getschedparam(attr, &sp);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getschedparam");
	printf("%sSchedul. priority=(%d)\n", prefix, sp.sched_priority);
	s = pthread_attr_getguardsize(attr, &v);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getguardsize");
	printf("%sGuard size       =(%zu) bytes\n", prefix, v);
	s = pthread_attr_getstack(attr, &stkaddr, &v);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_getstack");
	printf("%sStack address    =(%p)\n", prefix, stkaddr);
	printf("%sStack size       =(%#zx) bytes\n", prefix, v);
	printf("___________________ END_ATTR_DUMP____________________\n");
}

void	*funcionhilo(void *p)
{
	int		n;
	clock_t	ahora;
	int		ticks;

	ticks = rand() % CLOCKS_PER_SEC / 2;
	ahora = clock();
	printf("ticks=%d\n", ticks);
	n = 1;
	while (n < 10)
	{
		if (p)
			printf("\t%d\n", n * n);
		else
			printf("%d\n", n);
		n++;
		while ((clock() - ahora) < ticks)
			;
	}
	--g_hilos;
	return (NULL);
}


int	main(void)
{
	pthread_t		hilo1;
	pthread_t		hilo2;
	//void			*retorno;
	int				s;
	pthread_attr_t	attr;

	s = pthread_attr_init(&attr);
	if (s != 0)
		errc(EXIT_FAILURE, s, "pthread_attr_init");
	pthread_display_attr(&attr, "LMCD\t");
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_display_attr(&attr, "LMCD\t");
	g_hilos = 2;
	pthread_create(&hilo1, &attr, &funcionhilo, (void *) 1);
	pthread_create(&hilo2, &attr, &funcionhilo, NULL);
	//pthread_join(hilo1, &retorno);
	//pthread_join(hilo2, &retorno);
	while (g_hilos)
		sleep (1);
	return (0);
}
