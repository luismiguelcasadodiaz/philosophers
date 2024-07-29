/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni			*moni;
	int				i;

	if ((argc < 5) || (argc > 6))
		return (printf("Invalid argument number.\n"));
	moni = arg_ok(argc, argv);
	if (!moni)
		return (printf("Not positive arguments for an integer type.\n"));
	if (philo_create(moni))
		return (printf("System does not give me resources to simulate\n"));
	i = 1;
	while (i <= moni->num_phi)
		my_th_join(moni->thread_ids[i++]);
	t_moni_free(moni, FULL);
	return (0);
}
