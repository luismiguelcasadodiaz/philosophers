/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 17:57:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni			*moni;
	pthread_t		**threads_ids;
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
	threads_ids = philo_create(moni);
	i = 1;
	while (i <= moni->num_phi)
		my_th_join(threads_ids[i++]);
	return (0);
}
