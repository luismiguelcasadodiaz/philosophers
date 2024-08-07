/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:36:19 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 17:50:30 by luicasad         ###   ########.fr       */
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

void	lng_set_t_var(t_thread *t, long num)
{
	my_mutex_lock(t->s_eat_mtx);
	*t->s_eat_ms = num;
	t->num_lunchs--;
	my_mutex_unlock(t->s_eat_mtx);
}

void	lng_get_t_var(t_thread *t, long *s_eat_ms, int *num_lunchs)
{
	my_mutex_lock(t->s_eat_mtx);
	*s_eat_ms = t->s_eat_ms;
	*num_lunchs = t->num_lunchs;
	my_mutex_unlock(t->s_eat_mtx);
}
