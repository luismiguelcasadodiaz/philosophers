/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:36:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/28 19:18:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	*lng_create(long num)
{
	long	*ptr_lng;

	ptr_lng = (long *)malloc(sizeof(long));
	if (ptr_lng == NULL)
		return (NULL);
	*ptr_lng = num;
	return (ptr_lng);
}

void	lng_free(long	*ptr)
{
	free(ptr);
}

void	lng_set(long *ptr, pthread_mutex_t *mtx, long num)
{
	my_mutex_lock(mtx);
	*ptr = num;
	my_mutex_unlock(mtx);
}

long	lng_get(long *ptr, pthread_mutex_t *mtx)
{
	long	num;

	my_mutex_lock(mtx);
	num = *ptr;
	my_mutex_unlock(mtx);
	return (num);
}
