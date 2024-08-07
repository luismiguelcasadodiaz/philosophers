/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 17:57:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	monitor(t_moni *m)
{
	int		i;
	int		died;		
	long	now_ms;
	long	ate;

	died = 0;
	while (!died)
	{
		i = 1;
		while (i <= m->num_phi && !died)
		{
			lng_get_t_var(m->threads[i],ate, lunchs);
			now_ms = my_now_ms();
			if (ate != 0 && (now_ms - ate) > m->ttd)
			{
				philo_msg(" died\n", m->threads[i]);
				died = 1;
			}
			i++;
		}
	}
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
