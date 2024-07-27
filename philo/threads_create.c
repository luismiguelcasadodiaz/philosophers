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

pthread_t	**threads_create(int num)
{
	int				i;
	pthread_t	**thread_ids;

	thread_ids = (pthread_t **)malloc((num + 1) * sizeof(pthread_t *));
	if (thread_ids == NULL)
		exit(1);
	i = 0;
	while (i <= num)
	{
		thread_ids[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (thread_ids[i] == NULL)
		{
			while (--i >= 0)
				free(thread_ids[i]);
			free(thread_ids);
			exit(1);
		}
		thread_ids[i] = 0;
		i++;
	}
	return (thread_ids);
}
