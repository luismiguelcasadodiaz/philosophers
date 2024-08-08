/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 17:57:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_thread *t)
{
	if ((t->mynum % 2) == 0)
	{
		my_mutex_lock(t->forks[t->fork_r]);
		philo_msg(" has taken a fork", t);
		my_mutex_lock(t->forks[t->fork_l]);
		philo_msg(" has taken a fork", t);
		lng_set_t_var(t, my_now_ms());
		philo_msg(" is eating", t);
		usleep(1000 * t->tte);
		my_mutex_unlock(t->forks[t->fork_l]);
		my_mutex_unlock(t->forks[t->fork_r]);
	}
	else
	{
		my_mutex_lock(t->forks[t->fork_l]);
		philo_msg(" has taken a fork", t);
		my_mutex_lock(t->forks[t->fork_r]);
		philo_msg(" has taken a fork", t);
		lng_set_t_var(t, my_now_ms());
		philo_msg(" is eating", t);
		usleep(1000 * t->tte);
		my_mutex_unlock(t->forks[t->fork_r]);
		my_mutex_unlock(t->forks[t->fork_l]);
	}
}

void	*philo_thread(void *arg)
{
	t_thread		*t;

	t = (t_thread *)arg;
	my_mutex_lock(t->forks[t->num_phi + CASUALTY]);
	my_mutex_unlock(t->forks[t->num_phi + CASUALTY]);
	//t_thread_show(t);
	if (t->allborn)
	{
		if ((t->mynum % 2) == 0)
			usleep(5000);
		while (!lng_get(t->casualty, t->forks[t->num_phi + CASUALTY]))
		{
			eat(t);
			philo_msg(" is sleeping", t);
			usleep(1000 * t->tts);
			philo_msg(" is thinking", t);
		}
	}
	return ((void *)0);
}
