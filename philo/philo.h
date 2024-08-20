/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:32:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/08 19:09:11 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define FULL 1
# define PART 0
# define MUTEX_ADD 2

/* MUTEX_ADD 1   screen                                                       */
/* MUTEX_ADD 2   screen + casualties                              */
# define SCREEN   0
# define CASUALTY 1
/* ABSOLUT = 1 shows fulltime stamp ABSOLUT = 0 show simulation time          */
# ifndef ABSOLUT
#  define ABSOLUT 1
# endif

/* ************************************************************************** */
/* forks       Holds a pointer to all available mutexes                       */
/* casualty    Holds a pointer to a flag reporting if any philo died          */
/* allborn     Holds a pointer to a flag reporting if all num_phi were born   */
/* sim_ini_ms  Holds a pointer to a time stamp for simulation initiation      */
/* thread_id   Holds the thread identificator                                 */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* my_lunchs   Holds number of lunch eaten by this philosoper                 */
/* eating      Flag indicating the philosoper is eating now (not used)        */
/* mynum       Holds the number of this philosopher                           */
/* fork_l      Holds fork number to use with left hand                        */
/* fork_r      Holds fork number to use with right hand                       */
/* s_eat_ms    Holds last time this philosoher started to eat                 */
/* s_eat_mtx   THis muttex prevents data races for this previous information  */
/* ************************************************************************** */
typedef struct s_thread
{
	pthread_mutex_t	**forks;
	long			*casualty;
	int				allborn;
	long			sim_init_ms;
	pthread_t		thread_id;
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				num_lunchs;
	int				my_lunchs;
	int				eating;
	int				mynum;
	int				fork_l;
	int				fork_r;
	long			*s_eat_ms;
	pthread_mutex_t	*s_eat_mtx;
}	t_thread;
/* ************************************************************************** */
/* t_moni_set() helper funcion to test a CLI argument in the right field      */
/* forks       Holds a pointer to all available mutexes                       */
/* threads     Holds a pointer to all available threads identificators        */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* sim_ini_ms  Holds a pointer to a time stamp for simulation initiation      */
/* casualty    Holds a pointer to a flag reporting if any philo died          */
/* allborn     Holds a pointer to a flag reporting if all num_phi were born   */
/* ************************************************************************** */

typedef struct s_p_moni
{
	pthread_mutex_t	**forks;
	t_thread		**threads;
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				num_lunchs;
	long			sim_init_ms;
	long			*casualty;
	int				allborn;
}	t_moni;

long			*lng_create(long num);
void			lng_free(long	*ptr);
void			lng_set(long *ptr, pthread_mutex_t *mtx, long num);
long			lng_get(long *ptr, pthread_mutex_t *mtx);
void			lng_set_t_var(t_thread *t, long num);
void			lng_get_t_var(t_thread *t, long *s_eat_ms, int *num_lunchs);
t_thread		*t_thread_init(int num, t_moni *r);
void			t_thread_free(t_thread *r);
void			t_thread_show(t_thread *r);
t_moni			*t_moni_init(void);
void			t_moni_free(t_moni *r, int full);
void			t_moni_set(t_moni *r, int i, int num);
t_moni			*t_moni_copy_set(int mynum, t_moni *ori);
void			t_moni_show(t_moni *r);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
long			ft_atol(const char *s);
char			*ft_itoa(int n, int *pos);
char			*ft_ltoa(long n, int *pos);
long			my_now_ms(void);
void			my_usleep(int time);

t_moni			*arg_ok(int argc, char **argv);
int				arg_digits(char	*arg);
int				arg_range_int(char *arg, int *my_int);
int				my_mutex_lock(pthread_mutex_t	*alarm_mutex);
int				my_mutex_unlock(pthread_mutex_t	*alarm_mutex);
int				my_th_create(pthread_t *t, void *(*f)(void *), void *arg);
int				my_th_detach(pthread_t *t);
int				my_th_join(pthread_t t);
pthread_mutex_t	**forks_create(int num);
void			forks_free(pthread_mutex_t **forks, int num);
int				philo_create(t_moni *moni);
void			*philo_thread(void *arg);
void			*philo_thread_one(void *arg);
t_thread		**threads_create(t_moni *r);
void			threads_free(t_thread **threads_ids, int num);
void			threads_join(t_moni *moni);
int				philo_msg(char *msg, t_thread *a);
void			*monitor_thread(void *arg);
#endif
