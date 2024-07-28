/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/29 18:26:35 by luicasad         ###   ########.fr       */
=======
/*   Updated: 2024/07/28 21:15:40 by luicasad         ###   ########.fr       */
>>>>>>> 7fa1624 (no Exit, no Abort)
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_creat_one(t_moni *moni, int i)
{
	t_moni	*arg;

	while (i <= moni->num_phi)
	{
		arg = t_moni_copy_set(i, moni);
		if (my_th_create(arg->thread_ids[i], philo_thread, arg))
			return (1);
		i = i + 2;
	}
	return (0);
}

int	philo_create(t_moni *moni)
{
	int	result;

<<<<<<< HEAD
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
=======
	result = 0;
	my_mutex_lock(moni->forks[(moni->num_phi + INITTIME)]);
	if (philo_creat_one(moni, 1))
		result = 1;
	else if (philo_creat_one(moni, 2))
		result = 1;
	*moni->sim_init_ms = my_now_ms();
	my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
	return (result);
>>>>>>> 7fa1624 (no Exit, no Abort)
}
