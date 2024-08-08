/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:42:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 19:10:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_set_allborn_and_sim_init(t_moni *r)
{
	int			i;

	i = 1;
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

	while (i <= r->num_phi)
	{
		t = r->threads[i];
		if (my_th_create(&t->thread_id, philo_thread, t))
			return (1);
		i = i + 2;
	}
	return (0);
}

static int	philo_create_alone(t_moni *r)
{
	t_thread	*t;

	t = r->threads[1];
	if (my_th_create(&t->thread_id, philo_thread_one, t))
		return (1);
	return (0);
}

static int	philo_create_aux(t_moni *m)
{
	my_mutex_lock(m->forks[(m->num_phi + CASUALTY)]);
	if (m->num_phi == 1)
	{
		if (philo_create_alone(m))
			return (my_mutex_unlock(m->forks[(m->num_phi + CASUALTY)]), 1);
	}
	else
	{
		if (philo_creat_one(m, 1))
		{
			my_mutex_unlock(m->forks[(m->num_phi + CASUALTY)]);
			return (1);
		}
		else if (philo_creat_one(m, 2))
		{
			my_mutex_unlock(m->forks[(m->num_phi + CASUALTY)]);
			return (1);
		}
	}
	m->sim_init_ms = my_now_ms();
	m->allborn = 1;
	philo_set_allborn_and_sim_init(m);
	my_mutex_unlock(m->forks[(m->num_phi + CASUALTY)]);
	return (0);
}
int philo_create(t_moni *m)
{
	t_thread	*t;

	if (philo_create_aux(m))
		return (1);
	t = m->threads[0];
	if (my_th_create(&t->thread_id, monitor_thread, m))
		return (1);
	return (0);
}
