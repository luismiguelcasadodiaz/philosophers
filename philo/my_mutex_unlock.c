/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mutex_unlock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:12:11 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/25 12:13:11 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_mutex_unlock(pthread_mutex_t	*alarm_mutex)
{
	int	status;

	status = pthread_mutex_unlock (alarm_mutex);
	if (status != 0)
		err_abort (status, "Lock mutex");
}
