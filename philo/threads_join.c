/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:09:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/02 12:35:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

//loops thread_ids array, joinign only existing (!= 0) threads
void	threads_join(t_moni *moni)
{
	int				i;

	i = 0;
	while (++i <= moni->num_phi)
		if (*moni->thread_ids[i])
			my_th_join(moni->thread_ids[i]);
	t_moni_free(moni, FULL);
}
