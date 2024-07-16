/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_seen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:57:26 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 12:46:24 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_seen.c                                                          .*/
/*.@brief arg_seen() check if num has been previously seen in the arguments. .*/
/*.                                                                          .*/
/*.@param[in] num: the num to see if exists inside the stack.                .*/
/*.@param[in]   a: the stack to save the arguments.                          .*/
/*.                                                                          .*/
/*.@returns 0 if the argument has not been seen.   That is, it is not        .*/
/*.inside the stack. 1 if the argument has been seen.                        .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.Loops the stack looking for num. If there is not, pushes num into  stack  .*/
/*.and returns zero. Otherwiser returns one ==> arg_seen == True             .*/
/*.                                                                          .*/
/*.@author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
int	arg_seen(int num, t_pss *a)
{
	if (!pss_have(a, num))
	{
		pss_push(a, num, 0);
		return (0);
	}
	return (1);
}
