/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 12:41:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
/*
 *
 *
	 ---------------12345678901234567890
     ---------------         1         2		
   timestamp_in_ms X has taken a fork     19
   timestamp_in_ms X is eating            12
   timestamp_in_ms X is sleeping          14
   timestamp_in_ms X is thinking          14
   timestamp_in_ms X died		          07
 *
 *
 */
static void	philo_eat(t_moni *a, long *s_eat_ms)
{
	if ((a->num_phi == 2) && (a->mynum == 2))
	{
		my_mutex_lock(a->forks[a->fork_r]);
		my_mutex_lock(a->forks[a->fork_l]);
	}
	else
	{
		my_mutex_lock(a->forks[a->fork_l]);
		my_mutex_lock(a->forks[a->fork_r]);
	}
	philo_msg(a->mynum, " has taken a fork\n", 19, a->forks[0]);
	philo_msg(a->mynum, " is eating\n", 12, a->forks[0]);
	*s_eat_ms = my_now_ms();
	usleep(1000 * a->tte);
	if (a->num_phi == 2)
	{
		my_mutex_unlock(a->forks[a->fork_l]);
		my_mutex_unlock(a->forks[a->fork_r]);
	}
	else
	{
		my_mutex_unlock(a->forks[a->fork_r]);
		my_mutex_unlock(a->forks[a->fork_l]);
	}
}

static void	philo_actions(t_moni *a, int *morelunch)
{
	long			s_eat_ms;

	if (a->num_phi != 1)
	{
		philo_eat(a, &s_eat_ms);
		philo_msg(a->mynum, " is sleeping\n", 14, a->forks[0]);
		usleep(1000 * a->tts);
		philo_msg(a->mynum, " is thinking\n", 14, a->forks[0]);
	}
	if ((a->num_phi == 1) || (my_now_ms() - s_eat_ms > a->ttd))
	{
		philo_msg(a->mynum, " died\n", 7, a->forks[0]);
		*morelunch = 0;
	}
}

void	*philo_thread(void *a)
{
	int				lunchs;
	int				morelunch;

	lunchs = 0;
	morelunch = 1;
	while (morelunch)
	{
		philo_actions((t_moni *)a, &morelunch);
		lunchs++;
		morelunch = morelunch && !(((t_moni *)a)->num_lunchs == lunchs);
	}
	t_moni_free((t_moni *)a);
	return (NULL);
}
