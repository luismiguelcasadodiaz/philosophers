/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 10:39:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_creat_one(t_moni *r, int i)
{
	t_thread	*t;

	while (i <= r->num_phi)
	{
		t = r->threads[i];
		if ( my_th_create(&t->thread_id, philo_thread, t))
			return (1);
		i = i + 2;
	}
	return (0);
}

int	philo_create(t_moni *moni)
{
	my_mutex_lock(moni->forks[(moni->num_phi + INITTIME)]);
	lng_set(moni->allborn, moni->forks[(moni->num_phi + ALLBORN)], 0);
	if (philo_creat_one(moni, 1))
	{
		my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
		return (1);
	}
	else if (philo_creat_one(moni, 2))
	{
		my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
		return (1);
	}
	*moni->sim_init_ms = my_now_ms();
	lng_set(moni->allborn, moni->forks[(moni->num_phi + ALLBORN)], 1);
	my_mutex_unlock(moni->forks[(moni->num_phi + INITTIME)]);
	return (0);
}
