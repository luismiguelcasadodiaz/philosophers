/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 19:09:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_th_create(pthread_t *t, void *(*f)(void *), void *arg)
{
	int			s;

	s = pthread_create(t, NULL, (*f), (void *)arg);
	if (s != 0)
	{
		printf("Create thread<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		*t = 0;
		return (1);
	}
	return (0);
}
