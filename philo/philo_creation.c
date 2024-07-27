/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/29 18:26:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	philo_creat_one(t_moni *moni)
{
	int		i;
	t_moni	*arg;

	i = 1;
	while (i <= moni->num_phi)
	{
		arg = t_moni_copy_set(i, moni);
		my_th_create(arg->thread_ids[i], philo_thread, arg);
		i = i + 2;
	}
}

static void	philo_creat_two(t_moni *moni)
{
	int	i;
	t_moni	*arg;

	i = 2;
	while (i <= moni->num_phi)
	{
		arg = t_moni_copy_set(i, moni);
		my_th_create(arg->thread_ids[i], philo_thread, arg);
		i = i + 2;
	}
}

void	philo_create(t_moni *moni)
{
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
