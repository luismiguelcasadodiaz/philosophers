/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/29 18:43:14 by luicasad         ###   ########.fr       */
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
static int	take_forks(t_moni *a)
{
	int	result;

	result = 0;
	if ((a->mynum % 2) == 0)
	{
		my_mutex_lock(a->forks[a->fork_r]);
		result = philo_msg(" has taken a fork\n", 18, a);
		my_mutex_lock(a->forks[a->fork_l]);
	}
	else
	{
		my_mutex_lock(a->forks[a->fork_l]);
		result = philo_msg(" has taken a fork\n", 18, a);
		my_mutex_lock(a->forks[a->fork_r]);
	}
	return (result);
}

static void	release_forks(t_moni *a)
{
	if ((a->mynum % 2) == 0)
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

static int	philo_eat(t_moni *a, long *s_eat_ms)
{
	if (take_forks(a))
	{
		release_forks(a);
		return (1);
	}
	if (philo_msg(" has taken a fork\n", 18, a))
	{
		release_forks(a);
		return (1);
	}
	if (philo_msg(" is eating\n", 11, a))
	{
		release_forks(a);
		return (1);
	}
	*s_eat_ms = my_now_ms();
	usleep(1000 * a->tte);
	release_forks(a);
	return (0);
}

//if now - time started to eat last time is bigger time to die dies
//if time started to eat minus simulation started is bigger than time
//to die then dies
static int	philo_actions(t_moni *a, int *morelunch)
{
	long			s_eat_ms;
	long			now_ms;

	if (a->num_phi != 1)
	{
		if (philo_eat(a, &s_eat_ms))
			return (1);
		if (philo_msg(" is sleeping\n", 13, a))
			return (1);
		usleep(1000 * a->tts);
		if (philo_msg(" is thinking\n", 13, a))
			return (1);
	}
	now_ms = my_now_ms();
	if ((a->num_phi == 1) || (now_ms - s_eat_ms > a->ttd))
	{
		*morelunch = 0;
		if (philo_msg(" died\n", 6, a))
			return (1);
	}
	return (0);
}

void	*philo_thread(void *arg)
{
	int				lunchs;
	int				morelunch;
	t_moni			*a;

	a = (t_moni *)arg;
	lunchs = 0;
	morelunch = 1;
	my_mutex_lock(a->forks[a->num_phi + INITTIME]);
	my_mutex_unlock(a->forks[a->num_phi + INITTIME]);
	while (morelunch)
	{
		if (philo_actions((t_moni *)a, &morelunch))
		{
			t_moni_free((t_moni *)a, PART);
			return ((void *)1);
		}
		lunchs++;
		morelunch = morelunch && !(((t_moni *)a)->num_lunchs == lunchs);
	}
	t_moni_free((t_moni *)a, PART);
	return ((void *)0);
}
