/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/09 09:42:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

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
	threads_join(m);
	return (0);
}
