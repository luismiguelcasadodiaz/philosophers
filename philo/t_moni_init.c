/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_moni_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:11:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/16 19:35:59 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// creates the structure for the monitor
t_moni	*t_moni_init(void)
{
	t_moni	*r;

	r = (t_moni *)malloc(sizeof(t_moni));
	if (!r)
		return (NULL);
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = 0;
	return (r);
}

void	t_moni_free(t_moni *r)
{
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = 0;
	free(r);
}

void	t_moni_set(t_moni *r, int i, int num)
{
	if (i == 1)
		r->num_phi = num;
	if (i == 2)
		r->ttd = num;
	if (i == 3)
		r->tte = num;
	if (i == 4)
		r->tts = num;
	if (i == 5)
		r->num_lunchs = num;
}
