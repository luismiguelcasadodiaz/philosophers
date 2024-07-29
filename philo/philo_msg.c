/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:12:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/29 16:41:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

static char	*make_timestamp(int *ms_len, long sim_init_ms)
{
	struct timeval	t;
	long			now_ms;
	long			timestamp_ms;
	char			*ms;

	gettimeofday(&t, NULL);
	now_ms = (t.tv_sec * 1000000 + t.tv_usec) / 1000 ;
	if (ABSOLUT)
		timestamp_ms = now_ms;
	else
		timestamp_ms = now_ms - sim_init_ms;
	ms = ft_ltoa(timestamp_ms, ms_len);
	return (ms);
}

int	philo_msg(char *msg, int msg_len, t_moni *a)
{
	char			*ms;
	int				ms_len;
	char			*me;
	int				me_len;

	if (lng_get(a->casualty, a->forks[a->num_phi + CASUALTY]))
		return (1);
	if (msg[1] == 'd')
		lng_set(a->casualty, a->forks[a->num_phi + CASUALTY], 1);
	ms = make_timestamp(&ms_len, *a->sim_init_ms);
	me = ft_itoa(a->mynum, &me_len);
	my_mutex_lock(a->forks[SCREEN]);
	write(1, &ms[1], ms_len);
	write(1, me, me_len + 1);
	write(1, msg, msg_len);
	free(me);
	free(ms);
	my_mutex_unlock(a->forks[SCREEN]);
	return (0);
}
