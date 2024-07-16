/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_digi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 08:57:56 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 12:46:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argpar.h"
#include "libft.h"

/* ************************************************************************** */
/*.<*                                                                        .*/
/*.@file arg_digi.c                                                          .*/
/*.@brief arg_digits() verifies all arg's  chars are either +-0123456789.    .*/
/*.                                                                          .*/
/*.@param[in] arg: The string to validate as integer.                        .*/
/*.                                                                          .*/
/*.@returns                                                                  .*/
/*.1 if all char are all ok, 0 otherwise.                                    .*/
/*.                                                                          .*/
/*.@details                                                                  .*/
/*.An isolated sign (+/-) is not accepted.                                   .*/
/*.                                                                          .*/
/*.Set the hypothesis that arg it is ok.                                     .*/
/*.                                                                          .*/
/*.evaluates if first char of argument is +-0..9                             .*/
/*.Loops the argument string while each char validates against   0123456789  .*/
/*.                                                                          .*/
/*.@author LMCD (Luis Miguel Casado Diaz)                                    .*/
/*.>*                                                                        .*/
/* ************************************************************************** */
static int	check(char c)
{
	return ((c == '+') || (c == '-') || ft_isdigit(c));
}

int	arg_digits(char	*arg)
{
	int	i;
	int	ok;

	i = 0;
	if (((arg[i] == '+') || (arg[i] == '-')) && arg[i + 1] == '\0')
		return (0);
	ok = 1;
	ok = ok && check(arg[i++]);
	while (ok && arg[i] != '\0')
		ok = ok && ft_isdigit(arg[i++]);
	return (ok);
}
