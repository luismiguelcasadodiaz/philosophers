/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 11:57:34 by luicasad         ###   ########.fr       */
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
	result = philo_msg(" has taken a fork\n", 18, a);
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
	lng_set(a->s_eat_ms, a->s_eat_mtx, my_now_ms());
	if (philo_msg(" is eating\n", 11, a))
	{
		release_forks(a);
		return (1);
	}
	usleep(1000 * a->tte);
	release_forks(a);
	return (0);
}

//if now - time started to eat last time is bigger time to die dies
//if time started to eat minus simulation started is bigger than time
//to die then dies
static int	philo_actions(t_thread *a, int *morelunch)
{
	if (a->num_phi != 1)
	{
		if (philo_eat(a))
			return (1);
		if (philo_msg(" is sleeping\n", 13, a))
			return (1);
		usleep(1000 * a->tts);
		if (philo_msg(" is thinking\n", 13, a))
			return (1);
	}
	if (a->num_phi == 1)
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
	t_thread		*t;
	long			allborn;
	int				mtx;

	t = (t_thread *)arg;
	mtx = t->num_phi + INITTIME;
	my_mutex_lock(t->forks[mtx]);
	my_mutex_unlock(t->forks[mtx]);
	allborn = lng_get(t->allborn, t->forks[t->num_phi + ALLBORN]);
	lng_set(t->s_eat_ms, t->s_eat_mtx, lng_get(t->sim_init_ms, t->forks[mtx]));
	lunchs = 0;
	morelunch = 1;
	while (morelunch && allborn)
	{
		if (philo_actions(t, &morelunch))
			return ((void *)1);
		lunchs++;
		morelunch = morelunch && !(t->num_lunchs == lunchs);
	}
	return ((void *)0);
}
