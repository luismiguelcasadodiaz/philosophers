/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:39:10 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 08:44:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

pthread_mutex_t	**forks_create(int num)
{
	int				i;
	pthread_mutex_t	**forks;

	forks = (pthread_mutex_t **)malloc((num + 1) * sizeof(pthread_mutex_t *));
	if (forks == NULL)
		exit(1);
	i = 0;
	while (i <= num)
	{
		forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (forks[i] == NULL)
		{
			while (--i >= 0)
				free(forks[i]);
			free(forks);
			exit(1);
		}
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}
