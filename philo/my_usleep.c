/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:46:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 11:51:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	my_usleep(int time)
{
	long	now_ms;

	now_ms = my_now_ms();
	while (my_now_ms() - now_ms < time)
		usleep(time / 2);
}
