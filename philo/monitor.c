/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:58 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 19:11:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	iamdead(t_thread *t, int *my_lunchs)
{
	long	now_ms;
	long	ate;

	lng_get_t_var(t, &ate, my_lunchs);
	now_ms = my_now_ms();
	if ((now_ms - ate) > (t->ttd + 0))
	{
		philo_msg(" died", t);
		lng_set(t->casualty, t->forks[t->num_phi + CASUALTY], 1);
		return (1);
	}
	return (0);
}

static int	shall_i_stop(t_moni *m)
{
	int	i;
	int	my_lunchs;
	int	philo_all_eaten;

	i = 1;
	philo_all_eaten = 0;
	while (i <= m->num_phi)
	{
		if (iamdead(m->threads[i], &my_lunchs))
			return (1);
		if (m->num_lunchs != -1 && my_lunchs >= m->num_lunchs)
			philo_all_eaten++;
		i++;
	}
	if (philo_all_eaten == m->num_phi)
	{
		lng_set(m->casualty, m->forks[m->num_phi + CASUALTY], 1);
		return (1);
	}
	else
		return (0);
}

void	*monitor_thread(void *arg)
{
	t_moni *m;

	m=(t_moni *)arg;
	while (!shall_i_stop(m))
		usleep(1000);
	return (arg);
}
