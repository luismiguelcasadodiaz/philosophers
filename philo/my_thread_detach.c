/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_detach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 16:54:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_th_detach(pthread_t *t)
{
	int			status;

	status = pthread_detach(*t);
	if (status != 0)
		err_abort (status, "Detach thread");
}
