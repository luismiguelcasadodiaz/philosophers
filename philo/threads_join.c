/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/06 10:43:41 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

//loops thread_ids array, joinign only existing (!= 0) threads
void	threads_join(t_moni *moni)
{
	int				i;

	i = -1;
	while (++i <= moni->num_phi)
	{
		if (moni->threads[i]->thread_id != 0)
		{
			my_th_join(moni->threads[i]->thread_id);
			t_thread_free(moni->threads[i]);
		}
		else
			t_thread_free(moni->threads[i]);
	}

	//t_thread_free(moni->threads[0]);
	free(moni->threads);
	t_moni_free(moni, FULL);
}
