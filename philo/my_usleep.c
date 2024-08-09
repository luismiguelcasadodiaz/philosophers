/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:16:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 19:34:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	my_usleep(int time)
{
	long	now0_ms;
	long	now1_ms;

	now0_ms = my_now_ms();
	now1_ms = my_now_ms();
	while ((now1_ms - now0_ms) < time)
	{
		usleep(500);
		now1_ms = my_now_ms();
	}
}
