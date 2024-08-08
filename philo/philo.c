/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 14:35:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	iamdead(t_thread *t, int *my_lunchs)
{
	long	now_ms;
	long	ate;

	lng_get_t_var(t, &ate, my_lunchs);
	now_ms = my_now_ms();
	if ((now_ms - ate) > t->ttd)
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

static void	monitor(t_moni *m)
{
	while (!shall_i_stop(m))
		;
}

int	main(int argc, char	**argv)
{
	t_moni	*m;

	if ((argc < 5) || (argc > 6))
		return (printf("Invalid argument number.\n"));
	m = arg_ok(argc, argv);
	if (!m)
		return (printf("Not positive arguments for an integer type.\n"));
	if (philo_create(m))
	{
		threads_join(m);
		return (printf("System does not give me resources to simulate\n"));
	}
	monitor(m);
	threads_join(m);
	return (0);
}
