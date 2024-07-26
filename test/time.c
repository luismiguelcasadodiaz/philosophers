/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:33:22 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/26 10:10:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	s;
	struct timeval	e;
	long			e_usec;

	gettimeofday(&s, NULL);
	printf("start.tv_sec\t= %ld\n", s.tv_sec);
	printf("start.tv_usec\t= %ld\n", s.tv_usec);
	sleep(10);
	gettimeofday(&e, NULL);
	printf("end.tv_sec\t= %ld\n", e.tv_sec);
	printf("end.tv_usec\t= %ld\n", s.tv_usec);
	e_usec = (e.tv_sec - s.tv_sec) * 1000000 + (e.tv_usec - s.tv_usec);
	printf("Elapsed time: %ld microseconds\n", e_usec);
	printf("Elapsed time: %ld milliseconds\n", e_usec / 1000);
	return (0);
}
