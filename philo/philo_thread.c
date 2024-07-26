/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 21:52:14 by luicasad         ###   ########.fr       */
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
static void	philo_actions(t_moni *a, int *morelunch)
{
	long			s_eat_ms;

	my_mutex_lock(((t_moni *)a)->forks[((t_moni *)a)->fork_l]);
	my_mutex_lock(((t_moni *)a)->forks[((t_moni *)a)->fork_r]);
	philo_msg(a->mynum, " has taken a fork\n", 19, a->forks[0]);
	philo_msg(a->mynum, " is eating\n", 12, a->forks[0]);
	s_eat_ms = my_now_ms();
	usleep(1000 * ((t_moni *)a)->tte);
	my_mutex_unlock(((t_moni *)a)->forks[((t_moni *)a)->fork_r]);
	my_mutex_unlock(((t_moni *)a)->forks[((t_moni *)a)->fork_l]);
	philo_msg(a->mynum, " is sleeping\n", 14, a->forks[0]);
	usleep(1000 * ((t_moni *)a)->tts);
	philo_msg(a->mynum, " is thinking\n", 14, a->forks[0]);
	if (my_now_ms() - s_eat_ms > ((t_moni *)a)->ttd)
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
	return (a);
}
