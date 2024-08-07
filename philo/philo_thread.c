/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 18:19:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
static int	take_forks(t_thread *a)
{
	int		result;

	result = 0;
	my_mutex_lock(a->forks[a->fork_r]);
	result = philo_msg(" has taken a fork", a);
	my_mutex_lock(a->forks[a->fork_l]);
	return (result);
}

static void	release_forks(t_thread *a)
{
	my_mutex_unlock(a->forks[a->fork_l]);
	my_mutex_unlock(a->forks[a->fork_r]);
}

static int	philo_eat(t_thread *a)
{
	long	s_eat_ms;

	if (take_forks(a))
	{
		release_forks(a);
		return (1);
	}
	if (philo_msg(" has taken a fork", a))
	{
		release_forks(a);
		return (1);
	}
	s_eat_ms = my_now_ms();
	if (philo_msg(" is eating", a))
	{
		release_forks(a);
		return (1);
	}
	usleep(1000 * a->tte);
	lng_set_t_var(a, s_eat_ms);
	release_forks(a);
	return (0);
}

//if now - time started to eat last time is bigger time to die dies
//if time started to eat minus simulation started is bigger than time
//to die then dies
static int	philo_actions(t_thread *a)
{
	if (philo_eat(a))
		return (1);
	if (philo_msg(" is sleeping", a))
		return (1);
	usleep(1000 * a->tts);
	if (philo_msg(" is thinking", a))
		return (1);
	return (0);
}

void	*philo_thread(void *arg)
{
	int				lunchs;
	int				morelunch;
	t_thread		*t;

	t = (t_thread *)arg;
	my_mutex_lock(t->forks[t->num_phi + CASUALTY]);
	my_mutex_unlock(t->forks[t->num_phi + CASUALTY]);
	if (t->allborn)
	{
		if (((t->num_phi % 2) == 1) && ((t->mynum % 2) == 1))
			usleep(5000);
		lunchs = 0;
		morelunch = 1;
		while (morelunch)
		{
			if (philo_actions(t))
				return ((void *)1);
			lunchs++;
			morelunch = morelunch && (t->num_lunchs > 0);
		}
	}
	return ((void *)0);
}
void	*philo_thread_one(void *arg)
{
	t_thread		*t;

	t = (t_thread *)arg;
	my_mutex_lock(t->forks[t->num_phi + CASUALTY]);
	my_mutex_unlock(t->forks[t->num_phi + CASUALTY]);
	my_mutex_lock(t->forks[t->fork_r]);
	philo_msg(" has taken a fork", t);
	my_mutex_unlock(t->forks[t->fork_r]);
	usleep(1000 * t->ttd);
	philo_msg(" died", t);
	return ((void *)0);
}
