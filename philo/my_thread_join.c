/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_thread_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:18:55 by luicasad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/27 18:59:20 by luicasad         ###   ########.fr       */
=======
/*   Updated: 2024/07/28 21:31:27 by luicasad         ###   ########.fr       */
>>>>>>> 7fa1624 (no Exit, no Abort)
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_th_join(pthread_t *t)
{
<<<<<<< HEAD
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
=======
	int			s;

	s = pthread_join(*t, NULL);
	if (s != 0)
	{
		printf("Join thread<%s:%d> %s\n", __FILE__, __LINE__, strerror (s));
		return (1);
	}
	return (0);
>>>>>>> 7fa1624 (no Exit, no Abort)
}
