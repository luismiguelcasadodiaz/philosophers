/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/29 18:33:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_th_join(pthread_t *t)
{
	int			s;

	s = pthread_join(*t, NULL);
	if (s != 0)
	{
		printf("Join thread<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		return (1);
	}
	return (0);
}
