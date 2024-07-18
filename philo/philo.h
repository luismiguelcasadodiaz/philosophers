/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:32:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/16 19:41:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_p_moni
{
	int	num_phi;
	int	ttd;
	int	tte;
	int	tts;
	int	num_lunchs;

}	t_moni;

t_moni	*t_moni_init(void);
void	t_moni_free(t_moni *r);
void	t_moni_set(t_moni *r, int i, int num);
int	ft_isdigit(int c);

int	arg_digits(char	*arg);
#endif
