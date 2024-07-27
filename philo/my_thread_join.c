/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 18:59:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_th_join(pthread_t *t)
{
	int			status;
	int			*retval;

	retval = (int *)malloc(sizeof(int));
	status = pthread_join(*t, (void *)retval);
	if (status != 0)
		err_abort (status, "Join thread");
	printf("ret val = %d\n", *retval);
	if (*retval == 3)
		free(t);
	free(retval);
}
