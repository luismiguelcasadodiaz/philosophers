/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pag_367.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:13:12 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/20 13:31:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <bsd/err.h>

/* ************************************************************************** */
/* Como la entrada es manual, el hilo del calculo termina antes de que se     */
/* introduzca por el teclado el primer valor.                                 */
/* Todo el resultado queda a cero.                                            */
/* ************************************************************************** */
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
#ifndef MAX
# define MAX 10
#endif
int	datosiniciales[MAX];
int	resultado[MAX];

void	*preparadatos(void *p)
{
	int	n;

	printf("Introduce %d números:\n", MAX);
	n = -1;
	while (++n < MAX)
		scanf("%d\n", &datosiniciales[n]);
}

void	*generaresultado(void *p)
{
	int	n;

	n = -1;
	while (++n < MAX)
		resultado[n] = datosiniciales[n] * 5;
}

int	main(void)
{
	pthread_t	hilo1;
	pthread_t	hilo2;
	void		*retorno;
	int			n;

	pthread_create(&hilo1, NULL, preparadatos, NULL);
	pthread_create(&hilo2, NULL, generaresultado, NULL);

	pthread_join(hilo1, &retorno);
	pthread_join(hilo2, &retorno);

	n = -1;
	while (++n < MAX)
		if (resultado[n] != datosiniciales[n] * 5)
			printf("\t%d\t%d\n", datosiniciales[n], resultado[n]);
	return (0);
}
