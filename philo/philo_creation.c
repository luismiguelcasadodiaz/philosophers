/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 18:39:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free_threads_on_error(pthread_t **t, int i)
{
	i = i - 2;
	while (i >= 0)
	{
		free(t[i]);
		i = i - 2;
	}
}

void	philo_creat_one(pthread_t **t, t_moni *moni)
{
	int		i;
	t_moni	*arg;

	i = 1;
	while (i <= moni->num_phi)
	{
		t[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (t[i] == NULL)
		{
			philo_free_threads_on_error(t, i);
			free(t);
			exit(1);
		}
		arg = t_moni_copy_set(i, moni);
		my_th_create(t[i], philo_thread, arg);
		i = i + 2;
	}
}

void	philo_creat_two(pthread_t **t, t_moni *moni)
{
	int	i;

	i = 2;
	while (i <= moni->num_phi)
	{
		t[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (t[i] == NULL)
		{
			philo_free_threads_on_error(t, i);
			i = 1;
			while (i <= moni->num_phi)
			{
				free(t[i]);
				i = i + 2;
			}
			free(t);
			exit(1);
		}
		my_th_create(t[i], philo_thread, t_moni_copy_set(i, moni));
		i = i + 2;
	}
}

pthread_t	**philo_create(t_moni *moni)
{
	pthread_t	**t;

	moni->forks = forks_create(moni->num_phi);
	t = (pthread_t **)malloc(sizeof(pthread_t *) * (moni->num_phi + 1));
	if (t == NULL)
		exit (0);
	t[0] = NULL;
	philo_creat_one(t, moni);
	philo_creat_two(t, moni);
	return (t);
}

void	free_threads(pthread_t	**threads_ids, int num)
{
	int	i;

	i = 0;
	while (i < num)
		free(threads_ids[i++]);
	free(threads_ids);
}
