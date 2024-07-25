/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:32:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/25 13:09:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_p_moni
{
	int	num_phi;
	int	ttd;
	int	tte;
	int	tts;
	int	num_lunchs;
	int	fork_r;
	int	fork_l;

}	t_moni;

t_moni			*t_moni_init(void);
void			t_moni_free(t_moni *r);
void			t_moni_set(t_moni *r, int i, int num);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
long			ft_atol(const char *s);

t_moni			*arg_ok(int argc, char **argv);
int				arg_digits(char	*arg);
int				arg_range_int(char *arg, int *my_int);
void			my_mutex_lock(pthread_mutex_t	*alarm_mutex);
void			my_mutex_unlock(pthread_mutex_t	*alarm_mutex);
void			err_abort(int code, char *txt);
pthread_mutex_t	**forks_create(int num);
#endif
