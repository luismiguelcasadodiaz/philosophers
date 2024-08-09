/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_now_ms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:26:05 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 11:45:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long	my_now_ms(void)
{
	struct timeval	s;
	long			ms;

	gettimeofday(&s, NULL);
	ms = (s.tv_sec * 1000) + (s.tv_usec / 1000);
	return (ms);
}
