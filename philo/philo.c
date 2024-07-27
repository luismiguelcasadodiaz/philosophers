/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 14:03:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni			*moni;
	int				i;

	if ((argc < 5) || (argc > 6))
	{
		printf("Invalid argument number.\n");
		return (1);
	}
	moni = arg_ok(argc, argv);
	if (!moni)
	{
		printf("Arguments are not positive values for an integer type.\n");
		return (1);
	}
	printf("Creating  %d philosophers\n.", moni->num_phi);
	philo_create(moni);
	i = 1;
	while (i <= moni->num_phi)
		my_th_join(moni->thread_ids[i++]);
	free_threads(moni->thread_ids, moni->num_phi);
	forks_free(moni->forks, moni->num_phi);
	t_moni_free(moni);
	return (0);
}
