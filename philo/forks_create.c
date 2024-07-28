/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:39:10 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 18:44:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

pthread_mutex_t	**forks_create(int num)
{
	int				i;
	int				n;
	pthread_mutex_t	**forks;

	n = num + MUTEX_ADD;
	forks = (pthread_mutex_t **)malloc(n * sizeof(pthread_mutex_t *));
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (forks[i] == NULL)
		{
			while (--i >= 0)
				free(forks[i]);
			free(forks);
			return (NULL);
		}
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}
