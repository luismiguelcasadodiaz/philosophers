/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:15:25 by luicasad          #+#    #+#             */
/*   Updated: 2024/07/27 10:15:48 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int Global;

void*
Thread1(void *x) {
  Global = 42;
  return x;
}

int
main(void) {
  pthread_t t;
  pthread_create(&t, NULL, Thread1, NULL);
  Global = 43;
  pthread_join(t, NULL);
  return Global == 42 ? EXIT_SUCCESS : EXIT_FAILURE;
}
