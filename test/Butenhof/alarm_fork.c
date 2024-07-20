/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:21:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/21 00:43:27 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * alarm_fork.c
 *
 * This version of alarm.c uses fork to create a new process to
 * wait for each alarm to expire.
 */
#include <sys/types.h>
#include <wait.h>
#include "errors.h"

/*
 * Parse input line into seconds (%d) and a message
 * (%64[^\n]), consisting of up to 64 characters
 * separated from the seconds by whitespace.
 */

/*
 * In the parent, call waitpid() to collect any children that
 * have already terminated.
 */
static void	father_waits(void)
{
	int		esperar;
	pid_t	pid;

	esperar = 1;
	while (esperar)
	{
		pid = waitpid ((pid_t) - 1, NULL, WNOHANG);
		if (pid == (pid_t) - 1)
			errno_abort ("Wait for child");
		esperar = (pid != (pid_t)0);
	}
}

static void	father_forks(int seconds, char *message)
{
	pid_t	pid;

	pid = fork ();
	if (pid == (pid_t) - 1)
		errno_abort ("Fork");
	if (pid == (pid_t)0)
	{
		sleep (seconds);
		printf ("(%d) %s\n", seconds, message);
		exit (0);
	}
}

int	main(void)
{
	char	line[128];
	int		seconds;
	char	message[64];

	while (1)
	{
		printf ("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit (0);
		if (strlen (line) <= 1)
			continue ;
		if (sscanf (line, "%d %63[^\n]", &seconds, message) < 2)
			fprintf (stderr, "Bad command\n");
		else
		{
			if (seconds == 0)
				break ;
			father_forks(seconds, message);
		}
	}
	father_waits();
}
