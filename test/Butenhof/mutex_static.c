/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_static.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:44:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/23 08:52:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * mutex_static.c
 *
 * Demonstrate static initialization of a mutex.
 */
#include <pthread.h>
#include "errors.h"

/*
 * Declare a structure, with a mutex, statically initialized. This is the
 * same as using pthread_mutex_init, with the default attributes.
 */
/* Protects access to value */
/* Access protected by mutex */
typedef struct my_struct_tag
{
	pthread_mutex_t	mutex;
	int				value;
}	t_my_struct;

t_my_struct	g_data = {PTHREAD_MUTEX_INITIALIZER, 0};

int	main(void)
{
	return (0);
}
