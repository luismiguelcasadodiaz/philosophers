/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_thread_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:11:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 15:53:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************** */
/* t_thread_set_forks() define fork numbers in function od even/odd philo     */
/* number. This looks for a coolaborative strategy instead a competitive one  */
/* ************************************************************************** */
static void	t_thread_set_forks(t_thread *r)
{
	r->fork_l = r->mynum;
	if (r->mynum == r->num_phi)
		r->fork_r = 1;
	else
		r->fork_r = r->mynum + 1;
}

static void	t_thread_set_values(t_thread *t, t_moni *r)
{
	t->forks = r->forks;
	t->casualty = r->casualty;
	t->sim_init_ms = 0;
	t->allborn = 0;
	t->thread_id = 0;
	t->num_phi = r->num_phi;
	t->ttd = r->ttd;
	t->tte = r->tte;
	t->tts = r->tts;
	t->num_lunchs = r->num_lunchs;
	t->my_lunchs = 0;
	t->eating = 0;
}

/* ************************************************************************** */
/* t_thread_init() creates the argument to pass to thread creation            */
/* all fields set to zero/NULL                                                */
/* ************************************************************************** */
t_thread	*t_thread_init(int mynum, t_moni *r)
{
	t_thread	*t;

	t = (t_thread *)malloc(sizeof(t_thread));
	if (!t)
		return (NULL);
	t->s_eat_ms = lng_create(0);
	if (t->s_eat_ms == NULL)
	{
		free(t);
		return (NULL);
	}
	t->s_eat_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (t->s_eat_mtx == NULL)
	{
		free(t->s_eat_ms);
		free(t);
		return (NULL);
	}
	pthread_mutex_init(t->s_eat_mtx, NULL);
	t->mynum = mynum;
	t_thread_set_values(t, r);
	t_thread_set_forks(t);
	return (t);
}

/* ************************************************************************** */
/* t_thread_free() frees a thread Structure                                   */
/* ************************************************************************** */
void	t_thread_free(t_thread *t)
{
	pthread_mutex_destroy(t->s_eat_mtx);
	free(t->s_eat_mtx);
	free(t->s_eat_ms);
	free(t);
}

/* ************************************************************************** */
/* t_thread_show() shows a thread structure                                   */
/* ************************************************************************** */
void	t_thread_show(t_thread *r)
{
	my_mutex_lock(r->forks[SCREEN]);
	printf("-------------------------\n");
	printf("r->num_phi    = %d\n", r->num_phi);
	printf("r->ttd        = %d\n", r->ttd);
	printf("r->tte        = %d\n", r->tte);
	printf("r->tts        = %d\n", r->tts);
	printf("r->num_lunchs = %d\n", r->num_lunchs);
	printf("r->mynum      = %d\n", r->mynum);
	printf("r->fork_r     = %d\n", r->fork_r);
	printf("r->fork_l     = %d\n", r->fork_l);
	printf("-------------------------\n");
	my_mutex_unlock(r->forks[SCREEN]);
}
