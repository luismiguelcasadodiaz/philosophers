/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:56:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 14:14:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_pars.c                                                          .*/
/*.@brief arg_ok() checks if all argumentes are integert and save them into  .*/
/*.       a t_moni structure.                                                .*/
/*.@param[in] argc: number of arguments to verify.          .                .*/
/*.@param[in] argv: table  of arguments to verifi .                          .*/
/*.                                                                          .*/
/*.@returns a t_moni structure with arguments converted to integer if all are.*/
/*.  innteger. Otherwise returns NULL.                                       .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.Creates a structu t_moni to save the arguments                            .*/
/*.                                                                          .*/
/*.Set the hypothesis all arguments are ok (all_ok = 1)                      .*/
/*.                                                                          .*/
/*.Loops over the table of arguments verifing requirements:                  .*/
/*. 1.- The argument represents an integer.                                  .*/
/*. 2.- The integer fits in a  "int" type.                                   .*/
/*.                                                                          .*/
/*. if the argument satisfy all 2 requirements, it is saved into t_moni      .*/
/*.                                                                          .*/
/*.After processing all the table, if all arguments passed requirements,     .*/
/*.the arguments order in the stack is reversed to have first argument on    .*/
/*.stack's top and returns it. Otherwise returns NULL                        .*/
/*.                                                                          .*/
/*./author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
static void	validate_one_argument(char **argv, t_moni *r, int *all_ok, int i)
{
	int		num;

	*all_ok = *all_ok && arg_digits(argv[i]);
	if (*all_ok)
		*all_ok = *all_ok && (arg_range_int(argv[i], &num));
	if (*all_ok)
		*all_ok = *all_ok && (0 < num);
	if (*all_ok)
		t_moni_set(r, i, num);
}

static void	allocate_memory_lng(t_moni *r, int *ok)
{
	r->casualty = lng_create(0);
	if (r->casualty != NULL)
	{
		r->sim_init_ms = 0;
		r->allborn = 0;
		*ok = 1;
	}
}

static t_moni	*allocate_memory(t_moni *r)
{
	int	ok;

	ok = 0;
	r->forks = forks_create(r->num_phi);
	if (r->forks != NULL)
	{
		allocate_memory_lng(r, &ok);
		if (ok)
		{
			r->threads = threads_create(r);
			if (r->threads != NULL)
				return (r);
			else
			{
				lng_free(r->casualty);
			}
		}
		else
			forks_free(r->forks, r->num_phi);
	}
	t_moni_free(r, PART);
	return (NULL);
}

t_moni	*arg_ok(int argc, char **argv)
{
	int		i;
	int		all_ok;
	t_moni	*r;

	r = t_moni_init();
	if (!r)
		return (NULL);
	i = 1;
	all_ok = 1;
	while (all_ok && i < argc)
		validate_one_argument(argv, r, &all_ok, i++);
	if (all_ok)
		return (allocate_memory(r));
	t_moni_free(r, PART);
	return (NULL);
}
