/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:16:46 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 15:31:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	my_usleep(int time)
{
	long	now_ms;

	now_ms = my_now_ms();
	while (my_now_ms() - now_ms < time)
		usleep(time / 3);
}
