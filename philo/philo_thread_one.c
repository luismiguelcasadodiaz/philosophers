/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:53:17 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 14:38:46 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread_one(void *arg)
{
	t_thread		*t;

	t = (t_thread *)arg;
	my_mutex_lock(t->forks[t->num_phi + CASUALTY]);
	my_mutex_unlock(t->forks[t->num_phi + CASUALTY]);
	while (!lng_get(t->casualty, t->forks[t->num_phi + CASUALTY]))
	{
		my_mutex_lock(t->forks[t->fork_r]);
		philo_msg(" has taken a fork", t);
		my_mutex_unlock(t->forks[t->fork_r]);
		usleep(1000 * t->ttd);
		philo_msg(" died", t);
		lng_set(t->casualty, t->forks[t->num_phi + CASUALTY], 1);
	}
	return ((void *)0);
}
