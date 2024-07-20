/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:30:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/20 23:11:16 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * alarm.c
 *
 * Simple synchronous alarm program. This is used as a
 * reference for progressive examples of asynchronous
 * alarm programs.
 */
#include "errors.h"

/*
 * Parse input line into seconds (%d) and a message
 * (%64[^\n]), consisting of up to 64 characters
 * separated from the seconds by whitespace.
 */
int	main(void)
{
	int		seconds;
	char	line[128];
	char	message[64];

	while (1)
	{
		printf ("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit (0);
		if (strlen (line) <= 1)
			continue ;
		if (sscanf (line, "%d %60[^\n]", &seconds, message) < 2)
			fprintf (stderr, "Bad command\n");
		else
		{
			sleep (seconds);
			printf ("(%d) %s\n", seconds, message);
		}
	}
}
