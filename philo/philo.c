/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/18 19:32:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_moni	*moni;

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
	return(0);
}
