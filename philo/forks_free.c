/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 08:43:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 18:01:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	forks_free(pthread_mutex_t **forks, int num)
{
	int	i;
	int	n;

	n = num + MUTEX_ADD;
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i++]);
	}
	free(forks);
}
