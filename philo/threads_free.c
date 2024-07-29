/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   luicasad <luicasad@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:41:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 16:42:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	free_threads(pthread_t	**threads_ids, int num)
{
	int	i;

	i = 1;
	while (i < num)
		free(threads_ids[i++]);
	free(threads_ids);
}
