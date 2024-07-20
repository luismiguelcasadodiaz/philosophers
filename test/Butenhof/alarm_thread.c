/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:45:16 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/21 01:01:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "errors.h"

/*
 * alarm_fork.c
 *
 * This version of alarm.c uses pthread_create to create a
 * separate thread to wait for each alarm to expire.
 */
typedef struct s_alarm_tag
{
	int		seconds;
	char	message[64];
}	t_alarm;

void	*alarm_thread(void *arg)
{
	t_alarm	*alarm;
	int		status;

	alarm = (t_alarm *)arg;
	status = pthread_detach (pthread_self ());
	if (status != 0)
		err_abort (status, "Detach thread");
	sleep (alarm->seconds);
	printf ("(%d) %s\n", alarm->seconds, alarm->message);
	free (alarm);
	return (NULL);
}

int	main(void)
{
	int			status;
	char		line[128];
	t_alarm		*alarm;
	pthread_t	thread;

	while (1)
	{
		printf ("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit (0);
		if (strlen (line) <= 1)
			continue ;
		alarm = (t_alarm *)malloc (sizeof (t_alarm));
		if (alarm == NULL)
			errno_abort ("Allocate alarm");
		if (sscanf (line, "%d %63[^\n]", &alarm->seconds, alarm->message) < 2)
		{
			fprintf (stderr, "Bad command\n");
			free (alarm);
		}
		else
		{
			status = pthread_create (&thread, NULL, alarm_thread, alarm);
			if (status != 0)
				err_abort (status, "Create alarm thread");
		}
	}
}
