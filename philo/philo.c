/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 10:50:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni	*m;
	long	now_ms;
	long	ate;
	int		i;
	int		died;		

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
	my_mutex_lock(m->forks[m->num_phi + INITTIME]);
	my_mutex_unlock(m->forks[m->num_phi + INITTIME]);
	died = 0;
	while (!died)
	{
		i = 1;
		while (i <= m->num_phi && !died)
		{
			ate = lng_get(m->threads[i]->s_eat_ms, m->threads[i]->s_eat_mtx);
			now_ms = my_now_ms();
//			printf("(%d) n=%ld, a=%ld, d=%ld\n", i, now_ms, ate, now_ms - ate);
			if (ate != 0 && (now_ms - ate) > m->ttd)
			{
				philo_msg(" died\n", 6, m->threads[i]);
				died = 1;
			}
			i++;
		}
	}
	threads_join(m);
	return (0);
}
