/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/02 11:46:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni			*moni;

	if ((argc < 5) || (argc > 6))
		return (printf("Invalid argument number.\n"));
	moni = arg_ok(argc, argv);
	if (!moni)
		return (printf("Not positive arguments for an integer type.\n"));
	if (philo_create(moni))
	{
		threads_join(moni);
		return (printf("System does not give me resources to simulate\n"));
	}
	threads_join(moni);
	return (0);
}
