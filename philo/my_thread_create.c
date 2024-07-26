/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 17:01:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_th_create(pthread_t *t, void *(*f)(void *), t_moni *arg)
{
	int			status;

	status = pthread_create(t, NULL, (*f), arg);
	if (status != 0)
		err_abort (status, "Create thread");
}
