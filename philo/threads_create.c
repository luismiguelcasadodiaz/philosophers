/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:39:10 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 09:23:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_thread	**threads_create(t_moni *r)
{
	int			i;
	int			n;
	t_thread	**threads;

	n = r->num_phi + 1;
	threads = (t_thread **)malloc(n * sizeof(t_thread *));
	if (threads == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		threads[i] = t_thread_init(i, r);
		if (threads[i] == NULL)
		{
			while (--i >= 0)
				t_thread_free(threads[i]);
			free(threads);
			return (NULL);
		}
		threads[i]->thread_id = 0;
		i++;
	}
	return (threads);
}
