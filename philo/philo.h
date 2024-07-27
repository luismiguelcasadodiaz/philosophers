/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:32:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 14:04:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* ************************************************************************** */
/* t_moni_set() helper funcion to test a CLI argument in the right field      */
/* forks	   Holds a pointer to all available mutexes                       */
/* threads_ids Holds a pointer to all available threads identificators        */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* sim_ini_ms  Holds timestamp in ms for simulation initiation                */
/* mynum       Holds the number of this philosopher                           */
/* fork_l      Holds fork number to use with left hand                        */
/* fork_r      Holds fork number to use with right hand                       */
/* ************************************************************************** */

typedef struct s_p_moni
{
	pthread_mutex_t	**forks;
	pthread_t		**thread_ids;
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				num_lunchs;
	long			sim_init_ms;
	int				mynum;
	pthread_t		mythread_id;
	int				fork_l;
	int				fork_r;

}	t_moni;

t_moni			*t_moni_init(void);
void			t_moni_free(t_moni *r);
void			t_moni_set(t_moni *r, int i, int num);
t_moni			*t_moni_copy_set(int mynum, t_moni *ori);
void			t_moni_show(t_moni *r);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
long			ft_atol(const char *s);
char			*ft_itoa(int n, int *pos);
char			*ft_ltoa(long n, int *pos);
long			my_now_ms(void);

t_moni			*arg_ok(int argc, char **argv);
int				arg_digits(char	*arg);
int				arg_range_int(char *arg, int *my_int);
void			my_mutex_lock(pthread_mutex_t	*alarm_mutex);
void			my_mutex_unlock(pthread_mutex_t	*alarm_mutex);
void			my_th_create(pthread_t *t, void *(*f)(void *), t_moni *arg);
void			my_th_detach(pthread_t *t);
void			my_th_join(pthread_t *t);
void			err_abort(int code, char *txt);
pthread_mutex_t	**forks_create(int num);
void			forks_free(pthread_mutex_t **forks, int num);
pthread_t		**philo_create(t_moni *moni);
void			*philo_thread(void *arg);
pthread_t		**threads_create(int num);
void			free_threads(pthread_t	**threads_ids, int num);
void			philo_msg(int i, char *msg, int msg_len, pthread_mutex_t *mtx);
#endif
