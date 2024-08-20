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
	struct timeval		s;
	struct timeval		e;
	int			i;
	long			e_usec;

	i = 0;
	while (++i <= 200)
	{
		gettimeofday(&s, NULL);
		sleep(1);
		gettimeofday(&e, NULL);
		e_usec = (e.tv_sec - s.tv_sec) * 1000000 + (e.tv_usec - s.tv_usec);
		printf("%ld\n", e_usec);
	}
	return (0);
}
