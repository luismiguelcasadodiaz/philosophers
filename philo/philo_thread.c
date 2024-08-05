/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:00:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/05 10:27:50 by luicasad         ###   ########.fr       */
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
	long			now_ms;

	result = 0;
	my_mutex_lock(a->forks[a->fork_r]);
	result = philo_msg(" has taken a fork\n", 18, a);
	now_ms = my_now_ms();
	//printf("phil2 (%d) comio hace %ld a las %ld\n", a->mynum, now_ms - a->s_eat_ms, a->s_eat_ms);
	if ((now_ms - a->s_eat_ms) > a->ttd)
	{
		philo_msg(" died\n", 6, a);
		return (1);
	}
	my_mutex_lock(a->forks[a->fork_l]);
	return (result);
}

static void	release_forks(t_moni *a)
{
	my_mutex_unlock(a->forks[a->fork_l]);
	my_mutex_unlock(a->forks[a->fork_r]);
}

static int	philo_eat(t_moni *a)
{
	long			now_ms;

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
	now_ms = my_now_ms();
	//printf("phil2 (%d) comio hace %ld a las %ld\n", a->mynum, now_ms - a->s_eat_ms, a->s_eat_ms);
	if ((now_ms - a->s_eat_ms) > a->ttd)
	{
		philo_msg(" died\n", 6, a);
		return (1);
	}
	if (philo_msg(" is eating\n", 11, a))
	{
		release_forks(a);
		return (1);
	}
	a->s_eat_ms = my_now_ms();
	if (a->ttd >= a->tte)
		usleep(1000 * a->tte);
	else
	{
		usleep(1000 * a->ttd);
		if (philo_msg(" died\n", 6, a))
		{
			release_forks(a);
			return (1);
		}
	}
	release_forks(a);
	return (0);
}

//if now - time started to eat last time is bigger time to die dies
//if time started to eat minus simulation started is bigger than time
//to die then dies
static int	philo_actions(t_moni *a, int *morelunch)
{
	long			now_ms;

	if (a->num_phi != 1)
	{
		now_ms = my_now_ms();
		//printf("phil1 (%d) comio hace %ld a las %ld\n", a->mynum, now_ms - a->s_eat_ms, a->s_eat_ms);
		if ((now_ms - a->s_eat_ms) > a->ttd)
		{
			philo_msg(" died\n", 6, a);
			return (1);
		}
		if (philo_eat(a))
			return (1);
		if (philo_msg(" is sleeping\n", 13, a))
			return (1);
		if (a->ttd >= (a->tte + a->tts))
			usleep(1000 * a->tts);
		else
		{
			usleep(1000 * (a->ttd - a->tte));
			philo_msg(" died\n", 6, a);
			return (1);
		}
		now_ms = my_now_ms();
		//printf("phil3 (%d) comio hace %ld a las %ld\n", a->mynum, now_ms - a->s_eat_ms, a->s_eat_ms);
		if ((now_ms - a->s_eat_ms) > a->ttd)
		{	
			philo_msg(" died\n", 6, a);
			return (1);
		}
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
	t_moni			*a;
	long			allborn;

	a = (t_moni *)arg;
	lunchs = 0;
	morelunch = 1;
	my_mutex_lock(a->forks[a->num_phi + INITTIME]);
	my_mutex_unlock(a->forks[a->num_phi + INITTIME]);
	allborn = lng_get(a->allborn, a->forks[a->num_phi + ALLBORN]);
	a->s_eat_ms = lng_get(a->sim_init_ms, a->forks[a->num_phi + INITTIME]);
	while (morelunch && allborn)
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
