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

long	my_now_ms(void)
{
	struct timeval	s;
	long			ms;

	gettimeofday(&s, NULL);
	ms = (s.tv_sec * 1000) + (s.tv_usec / 1000);
	return (ms);
}

void	my_usleep(int time)
{
	long	now0_ms;
	long	now1_ms;

	now0_ms = my_now_ms();
	now1_ms = my_now_ms();
	while ((now1_ms - now0_ms) < time)
	{
		usleep(100);
		now1_ms = my_now_ms();
	}
}
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
		my_usleep(1000);
		gettimeofday(&e, NULL);
		e_usec = (e.tv_sec - s.tv_sec) * 1000000 + (e.tv_usec - s.tv_usec);
		printf("%ld\n", e_usec);
	}
	return (0);
}
