/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:39:10 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 18:42:31 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

pthread_t	**threads_create(int num)
{
	int				i;
	int				n;
	pthread_t		**thread_ids;

	n = num + 1;
	thread_ids = (pthread_t **)malloc(n * sizeof(pthread_t *));
	if (thread_ids == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		thread_ids[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (thread_ids[i] == NULL)
		{
			while (--i >= 0)
				free(thread_ids[i]);
			free(thread_ids);
			return (NULL);
		}
		*thread_ids[i] = 0;
		i++;
	}
	return (thread_ids);
}
