/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_detach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 21:29:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_th_detach(pthread_t *t)
{
	int			s;

	s = pthread_detach(*t);
	if (s != 0)
	{
		printf("Detach thread<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		return (1);
	}
	return (0);
}
