/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mutex_unlock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:12:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 21:24:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_mutex_unlock(pthread_mutex_t	*alarm_mutex)
{
	int	s;

	s = pthread_mutex_unlock (alarm_mutex);
	if (s != 0)
	{
		printf("Unlock mutex<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		return (1);
	}
	return (0);
}
