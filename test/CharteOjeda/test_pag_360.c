/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:11:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/19 19:13:08 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

void	*funcionhilo(void *p)
{
	int		n;
	clock_t	ahora;
	int		ticks;

	ticks = rand() % CLOCKS_PER_SEC / 2;
	ahora = clock();
	printf("ticks=%d\n", ticks);
	n = 1;
	while (n < 10)
	{
		if (p)
			printf("\t%d\n", n * n);
		else
			printf("%d\n", n);
		n++;
		while ((clock() - ahora) < ticks)
			;
	}
}

int	main(void)
{
	pthread_t	hilo1;
	pthread_t	hilo2;
	void		*retorno;

	pthread_create(&hilo1, NULL, &funcionhilo, (void *) 1);
	pthread_create(&hilo2, NULL, &funcionhilo, NULL);
	pthread_join(hilo1, &retorno);
	pthread_join(hilo2, &retorno);
	return (0);
}
