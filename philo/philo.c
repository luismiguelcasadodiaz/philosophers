/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/16 19:21:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char	**argv)
{
	t_moni	*moni;

	if ((argc < 5) || (argc > 6))
	{
		printf("Invalid argument number\n");
		return (1);
	}
	moni = arg_ok(argc, argv);
	if (!moni)
		return (1);
}
