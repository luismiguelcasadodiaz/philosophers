/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:12:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 08:56:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

static long	make_timestamp(long sim_init_ms)
{
	struct timeval	t;
	long			now_ms;

	gettimeofday(&t, NULL);
	now_ms = (t.tv_sec * 1000000 + t.tv_usec) / 1000 ;
	if (ABSOLUT)
		return (now_ms);
	else
		return (now_ms - sim_init_ms);
}

int	philo_msg(char *msg, t_thread *a)
{
	my_mutex_lock(a->forks[SCREEN]);
	if (!lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
		printf("%ld %d%s\n", make_timestamp(a->sim_init_ms), a->mynum, msg);
	my_mutex_unlock(a->forks[SCREEN]);
	return (0);
}
