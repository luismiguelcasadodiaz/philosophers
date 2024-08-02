/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/02 12:44:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_creat_one(t_moni *moni, int i)
{
	t_moni	*arg;

	while (i <= moni->num_phi)
	{
		arg = t_moni_copy_set(i, moni);
		if (i == 3 || my_th_create(arg->thread_ids[i], philo_thread, arg))
		{
			t_moni_free(arg, PART);
			return (1);
		}
		i = i + 2;
	}
	return (0);
}

int	philo_create(t_moni *moni)
{
	my_mutex_lock(moni->forks[(moni->num_phi + INITTIME)]);
	if (philo_creat_one(moni, 1))
	{	//result = 1;
		my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
		return (1);
	}
	else if (philo_creat_one(moni, 2))
	{
		//result = 1;
		my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
		return (1);
	}
	*moni->sim_init_ms = my_now_ms();
	my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
	return (0);
}
