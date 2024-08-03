/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_moni_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:11:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/03 08:53:51 by luicasad         ###   ########.fr       */
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
	r->thread_ids = NULL;
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = 0;
	r->sim_init_ms = NULL;
	r->casualty = NULL;
	r->allborn = NULL;
	r->mynum = 0;
	r->fork_r = 0;
	r->fork_l = 0;
	return (r);
}

/* ************************************************************************** */
/* t_moni_copy_set() creates a copy of monitoring structure adapting it for   */
/* the philosoper defined by mynum.                                           */
/* the CLI arguments in ori are transfered to the new structure.              */
/* ************************************************************************** */
t_moni	*t_moni_copy_set(int mynum, t_moni *ori)
{
	t_moni	*r;

	r = t_moni_init();
	r->forks = ori->forks;
	r->thread_ids = ori->thread_ids;
	r->num_phi = ori->num_phi;
	r->ttd = ori->ttd;
	r->tte = ori->tte;
	r->tts = ori->tts;
	r->num_lunchs = ori->num_lunchs;
	r->sim_init_ms = ori->sim_init_ms;
	r->casualty = ori->casualty;
	r->allborn = ori->allborn;
	r->mynum = mynum;
	r->fork_l = mynum;
	if (mynum == ori->num_phi)
		r->fork_r = 1;
	else
		r->fork_r = mynum + 1;
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
		threads_free(r->thread_ids, r->num_phi);
		lng_free(r->sim_init_ms);
		lng_free(r->casualty);
		lng_free(r->allborn);
	}
	else
	{
		r->forks = NULL;
		r->thread_ids = NULL;
		r->sim_init_ms = NULL;
		r->casualty = NULL;
		r->allborn = NULL;
	}
	r->num_phi = 0;
	r->ttd = 0;
	r->tte = 0;
	r->tts = 0;
	r->num_lunchs = 0;
	r->mynum = 0;
	r->fork_r = 0;
	r->fork_l = 0;
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
	printf("r->mynum      = %d\n", r->mynum);
	printf("r->mynum      = %d\n", r->mynum);
	printf("r->casualty   = %ld\n", *r->casualty);
	printf("r->allborn   = %ld\n", *r->allborn);
	printf("r->thread_id  = %d\n", (int)*r->thread_ids[r->mynum]);
	printf("r->fork_r     = %d\n", r->fork_r);
	printf("r->fork_l     = %d\n", r->fork_l);
}
