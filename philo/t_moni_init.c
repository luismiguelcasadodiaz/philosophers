/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_moni_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:11:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 15:54:17 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************** */
/* t_moni_init() creates an empty structure for monitoring.                   */
/* all fields set to zero/NULL                                                */
/* ************************************************************************** */
t_moni	*t_moni_init(void)
{
	t_moni	*r;

	r = (t_moni *)malloc(sizeof(t_moni));
	if (!r)
		return (NULL);
	r->forks = NULL;
	r->threads = NULL;
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = -1;
	r->sim_init_ms = 0;
	r->casualty = NULL;
	r->allborn = 0;
	return (r);
}

/* ************************************************************************** */
/* t_moni_free() frees a monitoring structure                                 */
/* ************************************************************************** */
void	t_moni_free(t_moni *r, int full)
{
	if (full)
	{
		forks_free(r->forks, (r->num_phi));
		free(r->casualty);
	}
	else
	{
		r->forks = NULL;
		r->threads = NULL;
		r->casualty = NULL;
	}
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = 0;
	r->allborn = 0;
	r->sim_init_ms = 0;
	free(r);
}

/* ************************************************************************** */
/* t_moni_set() helper funcion to test a CLI argument in the right field      */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* t_moni_show() shows a monitoring structure                                 */
/* ************************************************************************** */
void	t_moni_show(t_moni *r)
{
	printf("r->num_phi    = %d\n", r->num_phi);
	printf("r->ttd        = %d\n", r->ttd);
	printf("r->tte        = %d\n", r->tte);
	printf("r->tts        = %d\n", r->tts);
	printf("r->num_lunchs = %d\n", r->num_lunchs);
	printf("r->casualty   = %ld\n", *r->casualty);
	printf("r->allborn   = %d\n", r->allborn);
}
