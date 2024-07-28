/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mutex_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:11:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 21:21:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_mutex_lock(pthread_mutex_t	*alarm_mutex)
{
	int	s;

	s = pthread_mutex_lock (alarm_mutex);
	if (s != 0)
	{
		printf("Lock mutex<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		return (1);
	}
	return (0);
}
