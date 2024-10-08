/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:30:42 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/25 10:36:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <time.h>
#include "errors.h"

/*
 * alarm_mutex.c
 *
 * This is an enhancement to the alarm_thread.c program, which
 * created an "alarm thread" for each alarm command. This new
 * version uses a single alarm thread, which reads the next
 * entry in a list. The main thread places new requests onto the
 * list, in order of absolute expiration time. The list is
 * protected by a mutex, and the alarm thread sleeps for at
 * least 1 second, each iteration, to ensure that the main
 * thread can lock the mutex to add new work to the list.
 */

/*
 * The "alarm" structure now contains the time_t (time since the
 * Epoch, in seconds) for each alarm, so that they can be
 * sorted. Storing the requested number of seconds would not be
 * enough, since the "alarm thread" cannot tell how long it has
 * been on the list.
 */
typedef struct alarm_tag
{
	struct alarm_tag	*link;
	int					seconds;
	time_t				time;
	char				message[64];
	void				*the_list;
}	t_alarm;

pthread_mutex_t	alarm_mutex = PTHREAD_MUTEX_INITIALIZER;

/*
 * The alarm thread's start routine.
 */
/*
 * Loop forever, processing commands. The alarm thread will
 * be disintegrated when the process exits.
 */
/*
 * If the alarm list is empty, wait for one second. This
 * allows the main thread to run, and read another
 * command. If the list is not empty, remove the first
 * item. Compute the number of seconds to wait -- if the
 * result is less than 0 (the time has passed), then set
 * the sleep_time to 0.
 */
/*
 * Unlock the mutex before waiting, so that the main
 * thread can lock it to insert a new alarm request. If
 * the sleep_time is 0, then call sched_yield, giving
 * the main thread a chance to run if it has been
 * readied by user input, without delaying the message
 * if there's no input.
 */
/*
 * If a timer expired, print the message and free the
 * structure.
 */
void	*alarm_thread(void *arg)
{
	t_alarm	*alarm;
	int		sleep_time;
	time_t	now;
	int		status;

	while (1)
	{
		status = pthread_mutex_lock (&alarm_mutex);
		if (status != 0)
			err_abort (status, "Lock mutex");
		alarm = ((t_alarm *)arg)->link;
		if (alarm == NULL)
			sleep_time = 1;
		else
		{
			((t_alarm *)arg)->link = alarm->link;
			now = time (NULL);
			if (alarm->time <= now)
				sleep_time = 0;
			else
				sleep_time = alarm->time - now;
			printf ("[waiting: %ld(%d)\"%s\"]\n", alarm->time, \
			sleep_time, alarm->message);
		}
		status = pthread_mutex_unlock (&alarm_mutex);
		if (status != 0)
			err_abort (status, "Unlock mutex");
		if (sleep_time > 0)
			sleep (sleep_time);
		else
			sched_yield ();
		if (alarm != NULL)
		{
			printf ("(%d) %s\n", alarm->seconds, alarm->message);
			free (alarm);
		}
	}
}

static void	my_mutex_lock(pthread_mutex_t	*alarm_mutex)
{
	int	status;

	status = pthread_mutex_lock (alarm_mutex);
	if (status != 0)
		err_abort (status, "Lock mutex");
}

static void	my_mutex_unlock(pthread_mutex_t	*alarm_mutex)
{
	int	status;

	status = pthread_mutex_unlock (alarm_mutex);
	if (status != 0)
		err_abort (status, "Lock mutex");
}

static void	my_thread_create(pthread_t *t, void *(*f)(void *), t_alarm *arg)
{
	int			status;

	status = pthread_create(t, NULL, (*f), arg);
	if (status != 0)
		err_abort (status, "Create alarm thread");
}
/*
 * Parse input line into seconds (%d) and a message
 * (%64[^\n]), consisting of up to 64 characters
 * separated from the seconds by whitespace.
 */

/*
 * Insert the new alarm into the list of alarms,
 * sorted by expiration time.
 */
/*
 * If we reached the end of the list, insert the new
 * alarm there. ("next" is NULL, and "last" points
 * to the link field of the last item, or to the
 * list header).
 */
void	alarm_add_to_list(t_alarm *alarm_list, t_alarm *alarm)
{
	t_alarm		**last;
	t_alarm		*next;

	my_mutex_lock(&alarm_mutex);
	alarm->time = time (NULL) + alarm->seconds;
	last = &alarm_list->link;
	next = *last;
	while (next != NULL)
	{
		if (next->time >= alarm->time)
		{
			alarm->link = next;
			*last = alarm;
			break ;
		}
		last = &next->link;
		next = next->link;
	}
	if (next == NULL)
	{
		*last = alarm;
		alarm->link = NULL;
	}
	printf ("[list: ");
	for (next = alarm_list->link; next != NULL; next = next->link)
		printf ("%ld(%ld)[\"%s\"] ", next->time,
			next->time - time (NULL), next->message);
	printf ("]\n");
	my_mutex_unlock(&alarm_mutex);
}

int	main(void)
{
	char		line[128];
	t_alarm		*alarm;
	pthread_t	thread;
	t_alarm		*thread_arg;

	thread_arg = (t_alarm *)malloc (sizeof (t_alarm));
	thread_arg->link = NULL;
	my_thread_create(&thread, alarm_thread, thread_arg);
	while (1)
	{
		printf ("alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit (0);
		if (strlen (line) <= 1)
			continue ;
		alarm = (t_alarm *)malloc (sizeof (t_alarm));
		if (alarm == NULL)
			errno_abort ("Allocate alarm");
		if (sscanf(line, "%d %63[^\n]", &alarm->seconds, alarm->message) < 2)
		{
			fprintf (stderr, "Bad command\n");
			free (alarm);
		}
		else
			alarm_add_to_list(thread_arg, alarm);
	}
}
