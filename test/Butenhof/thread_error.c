/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:09:08 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/21 11:13:49 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * thread_error.c
 *
 * Demonstrate detection of errors from a typical POSIX 1003.1c-1995
 * function, pthread_join.
 */
/*
 * Attempt to join with an uninitialized thread ID. On most
 * implementations, this will return an ESRCH error code. If
 * the local (and uninitialized) pthread_t happens to be a valid
 * thread ID, it is almost certainly that of the initial thread,
 * which is running main(). In that case, your Pthreads
 * implementation may either return EDEADLK (self-deadlock),
 * or it may hang. If it hangs, quit and try again.
 */
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	main(void)
{
	pthread_t	thread;
	int			status;

	status = pthread_join (thread, NULL);
	if (status != 0)
		fprintf (stderr, "error %d: %s\n", status, strerror (status));
	return (status);
}
