/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/27 19:09:32 by luicasad         ###   ########.fr       */
=======
/*   Updated: 2024/07/28 22:49:14 by luicasad         ###   ########.fr       */
>>>>>>> 7fa1624 (no Exit, no Abort)
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
		philo_msg(a->mynum, " has taken a fork\n", 18, a->forks[0]);
		my_mutex_lock(a->forks[a->fork_l]);
	}
	else
	{
		my_mutex_lock(a->forks[a->fork_l]);
		philo_msg(a->mynum, " has taken a fork\n", 18, a->forks[0]);
		my_mutex_lock(a->forks[a->fork_r]);
	}
	philo_msg(a->mynum, " has taken a fork\n", 18, a->forks[0]);
	philo_msg(a->mynum, " is eating\n", 11, a->forks[0]);
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

static void	philo_actions(t_moni *a, int *morelunch, int *died)
{
	long			s_eat_ms;

	if (a->num_phi != 1)
	{
		if (!lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
			philo_eat(a, &s_eat_ms);
		if (!lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
		{
			philo_msg(a->mynum, " is sleeping\n", 13, a->forks[0]);
			usleep(1000 * a->tts);
		}
		if (!lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
			philo_msg(a->mynum, " is thinking\n", 13, a->forks[0]);
	}
	if ((a->num_phi == 1) || (my_now_ms() - s_eat_ms > a->ttd))
	{
		lng_set(a->casualty, a->forks[a->num_phi + CASUALTY], 1);
		philo_msg(a->mynum, " died\n", 6, a->forks[0]);
		*morelunch = 0;
		*died = 1;
	}
}

void	*philo_thread(void *arg)
{
	int				lunchs;
	int				morelunch;
<<<<<<< HEAD
	int				died;

	died = 0;
	lunchs = 0;
	morelunch = 1;
	while (morelunch && !died)
=======
	t_moni			*a;

	a = (t_moni *)arg;
	lunchs = 0;
	morelunch = 1;
	my_mutex_lock(a->forks[a->num_phi + INITTIME]);
	my_mutex_unlock(a->forks[a->num_phi + INITTIME]);
	while (morelunch && \
			!lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
>>>>>>> 7fa1624 (no Exit, no Abort)
	{
		philo_actions((t_moni *)a, &morelunch, &died);
		lunchs++;
		morelunch = morelunch && !(((t_moni *)a)->num_lunchs == lunchs);
	}
<<<<<<< HEAD
	t_moni_free((t_moni *)a);
	if (died) 
		return ((void *)3);
	else
		return ((void *)0);
=======
	t_moni_free((t_moni *)a, PART);
	return (NULL);
>>>>>>> 7fa1624 (no Exit, no Abort)
}
