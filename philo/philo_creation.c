/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 21:12:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	**philo_create(t_moni *moni)
{
	pthread_t	**t;
	int			i;

	t = (pthread_t **)malloc(sizeof(pthread_t *) * (moni->num_phi + 1));
	if (t == NULL)
		exit (0);
	i = 1;
	while (i <= moni->num_phi)
	{
		t[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (t[i] == NULL)
		{
			i = i - 2;
			while (i >= 0)
			{
				free(t[i]);
				i = i - 2;
			}
			free(t);
			exit(1);
		}
		my_th_create(t[i], philo_thread, t_moni_copy_set(i, moni));
		i = i + 2;
	}
	i = 2;
	while (i <= moni->num_phi)
	{
		t[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (t[i] == NULL)
		{
			i = i - 2;
			while (--i >= 0)
			{
				free(t[i]);
				i = i - 2;
			}
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
	return (t);
}
