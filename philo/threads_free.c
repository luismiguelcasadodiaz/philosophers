/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:18:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 19:09:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_free(pthread_t	**threads_ids, int num)
{
	int	i;

	i = 0;
	while (i <= num)
		free(threads_ids[i++]);
	free(threads_ids);
}
