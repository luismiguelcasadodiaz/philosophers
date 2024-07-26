/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 17:16:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_th_join(pthread_t *t)
{
	int			status;

	status = pthread_join(*t, NULL);
	if (status != 0)
		err_abort (status, "Join thread");
}
