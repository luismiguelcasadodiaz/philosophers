/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:18:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/05 11:17:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_free(t_thread	**threads, int num)
{
	int	i;

	i = 0;
	while (i <= num)
		free(threads[i++]);
	free(threads);
}
