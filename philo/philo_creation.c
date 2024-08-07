/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 17:06:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_set_allborn_and_sim_init(t_moni *r)
{
	int			i;

	i = 0;
	while (i <= r->num_phi)
	{
		*r->threads[i]->s_eat_ms = r->sim_init_ms;
		r->threads[i]->sim_init_ms = r->sim_init_ms;
		r->threads[i]->allborn = r->allborn;
		i = i + 1;
	}
}

static int	philo_creat_one(t_moni *r, int i)
{
	t_thread	*t;

	if (r->num_phi == 1)
	{
		t = r->threads[r->num_phi];
		if (my_th_create(&t->thread_id, philo_thread_one, t))
			return (1);
		return (0);
	}

	while (i <= r->num_phi)
	{
		t = r->threads[i];
		if (my_th_create(&t->thread_id, philo_thread, t))
			return (1);
		i = i + 1;
	}
	return (0);
}

int	philo_create(t_moni *moni)
{
	my_mutex_lock(moni->forks[(moni->num_phi + CASUALTY)]);
	if (philo_creat_one(moni, 1))
	{
		my_mutex_unlock(moni->forks[(moni->num_phi + CASUALTY)]);
		return (1);
	}
//	else if (philo_creat_one(moni, 2))
//	{
//		my_mutex_unlock(moni->forks[(moni->num_phi + CASUALTY)]);
//		return (1);
//	}
	moni->sim_init_ms = my_now_ms();
	moni->allborn = 1;
	philo_set_allborn_and_sim_init(moni);
	my_mutex_unlock(moni->forks[(moni->num_phi + CASUALTY)]);
	return (0);
}
