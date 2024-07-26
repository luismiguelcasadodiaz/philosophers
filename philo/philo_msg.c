/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:12:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 14:30:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

void	philo_msg(int i, char *msg, int msg_len, pthread_mutex_t *mtx)
{
	struct timeval	t;
	char			*ms;
	int				ms_len;
	char			*me;
	int				me_len;

	gettimeofday(&t, NULL);
	ms = ft_ltoa(((t.tv_sec * 1000000 + t.tv_usec) / 1000), &ms_len);
	me = ft_itoa(i, &me_len);
	my_mutex_lock(mtx);
	write(1, ms, ms_len + 1);
	write(1, me, me_len + 1);
	write(1, msg, msg_len);
	my_mutex_unlock(mtx);
	free(me);
	free(ms);
}
