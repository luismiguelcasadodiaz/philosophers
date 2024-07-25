/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mutex_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:11:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/25 12:13:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_mutex_lock(pthread_mutex_t	*alarm_mutex)
{
	int	status;

	status = pthread_mutex_lock (alarm_mutex);
	if (status != 0)
		err_abort (status, "Lock mutex");
}
