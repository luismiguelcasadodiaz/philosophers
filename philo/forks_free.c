/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 08:43:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 12:49:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	forks_free(pthread_mutex_t **forks, int num)
{
	int	i;

	i = 0;
	while (i <= num)
		free(forks[i++]);
	free(forks);
}
