/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:12:32 by luicasad          #+#    #+#             */
/*   Updated: 2024/08/07 10:29:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* ************************************************************************** */
/* allocate_space_for() allocates memory to show int n as a string            */
/*                                                                            */
/* GETS                                                                       */
/*  n   : is the integer to convert to string                                 */
/*  *pos: is string length for required to show int n as a string             */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing, but worth to know that pos is a variable passed by reference     */
/*  That communicates to calling function the string's length of the required */
/*  string to show int n as an string.                                        */
/*                                                                            */
/* OPERATES                                                                   */
/*  When n is negative (n <  0) at least requires 2-figure string.            */
/*  When n is positive (0 <= n) at least requires 1-figure string.            */
/*                                                                            */
/*  n /= 10 removes less significative digit from n.                          */
/*                                                                            */
/*  While there are digits it counts and removes digits.                      */
/*                                                                            */
/*  Once number of digits in known, allocates memory for the figures plus the */
/*  string null-terminator.                                                   */
/*                                                                            */
/*  if there is memory availabel initializes the string with white spaces and */
/*  returns the new creates string.                                           */
/*                                                                            */
static char	*allocate_space_fori(int n, int *pos)
{
	char	*str;
	int		figures;

	if (n < 0)
		figures = 2;
	else
		figures = 1;
	n /= 10;
	while (n)
	{
		figures = figures + 1;
		n /= 10;
	}
	*pos = 0;
	str = (char *)malloc((figures + 1) * sizeof(char));
	if (str != NULL)
	{
		*pos = figures;
		str[figures] = '\0';
		while (figures)
			str[--figures] = ' ';
		str[figures] = ' ';
	}
	return (str);
}

/* ************************************************************************** */
/* aux_itoa()is a recursive function that extract digits from an integer and  */
/* inserts them in the right position of a string with the right spaces to    */
/* hold all figures comming from the integer.                                 */
/*                                                                            */
/* GETS                                                                       */
/*  n     : The integer to extract digits from.                               */
/*  **str : Address of the pointer to  the string to append to digit          */
/*  *pos  : The lenght of the string that holds the integer.                  */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing, but worths to be aware that thru **str there is communication    */
/*  with the calling function.                                                */
/*                                                                            */
/* OPERATES                                                                   */
/*  Treates diferently accordingly to integer's sign.                         */
/*                                                                            */
/*  When the integer has more than one digit, reduce integer size dividing    */
/*  by 10.                                                                    */
/*                                                                            */
/*  When the integer has one digit (n <= 9), calculate his ascii char.        */
/*                                                                            */
/*                         num = 48 + n % 10                                  */
/*                                                                            */
/*  When n is INT_MIN (-2147 483 648) the required sign change happens in     */
/*  the result of the modulo operation. I wait to change the sign when the    */
/*  integer is small.                                                         */
/*                                                                            */
/*             ----------------------------------------                       */
/*                         num = 48 + (-n % 10)                               */
/*  That does not work with INT_MIN                                           */
/*                                                                            */
/*  Recursively the function extract the less significant figure from the int */
/*  in such a way the figure is inserted in the string from the right to the  */
/*  left, from n towards zero index. Then in each recursive call we have to   */
/*  decrease the position where to insert the figure (pos -1)                 */
/*                                                                            */

static void	aux_itoa(int n, char **str, int pos)
{
	char	num;

	if (0 < n)
	{
		if (9 < n)
			aux_itoa(n / 10, str, pos - 1);
		num = 48 + n % 10;
	}
	else
	{
		if (n < -9)
			aux_itoa(n / 10, str, pos - 1);
		num = n % 10;
		num = 48 - num;
	}
	str[0][pos] = num;
}

/* ft_itoa() allocates (with malloc(3)) and returns a strings representing    */
/* the integer received as an argument.                                       */
/* Negative numbers must be handlepointer                                .    */
/*                                                                            */
/* GETS                                                                       */
/*  n: the integer to convert                                                 */
/*                                                                            */
/* RETURNS                                                                    */
/*   The string representing the intege                                       */
/*   NULL if memory allocation fails.                                         */
/*                                                                            */
/* OPERATION                                                                  */
/*  Starts creating an empty (filled wiht spaces) string of enought lenght    */
/*  to hold all figures in the integer.                                       */
/*                                                                            */
/*  When n = 0 add a '0' to the empty string n the position 0 of a string of  */
/*  length 1.                                 */
/*                                                                            */
/*  When n is positive convert the integer into string                        */
/*                                                                            */
/*  When n is negative convert the integer into string and add '-' to head    */
/*                                                                            */
/* PROBLEMS I GOT                                                             */
/* I complicated my life with an approach to allocate memory for the string   */
/* representing the integer gradually as new digits are required. You can see */
/* it in this repository in ft_itoa_one_by_one.c                              */
/*                                                                            */
/* As i did not manage to pass the fsoares test ft_itoa(0), then i figured    */
/* out this other approach i can call ft_itoa_all_at_once.c                   */
/*                                                                            */
/* I learn to deal with a pointer passed by reference to a function           */

char	*ft_itoa(int n, int *pos)
{
	char	*str;

	str = allocate_space_fori(n, pos);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n > 0)
		{
			aux_itoa(n, &str, *pos);
		}
		if (n < 0)
		{
			aux_itoa(n, &str, *pos);
			str[0] = '-';
		}
	}
	return (str);
}

static char	*allocate_space_for(long n, int *pos)
{
	char	*str;
	int		figures;

	if (n < 0)
		figures = 2;
	else
		figures = 1;
	n /= 10;
	while (n)
	{
		figures = figures + 1;
		n /= 10;
	}
	*pos = 0;
	str = (char *)malloc((figures + 1) * sizeof(char));
	if (str != NULL)
	{
		*pos = figures;
		str[figures] = '\0';
		while (figures)
			str[--figures] = ' ';
		str[figures] = ' ';
	}
	return (str);
}

/* ************************************************************************** */
/* aux_itoa()is a recursive function that extract digits from an integer and  */
/* inserts them in the right position of a string with the right spaces to    */
/* hold all figures comming from the integer.                                 */
/*                                                                            */
/* GETS                                                                       */
/*  n     : The integer to extract digits from.                               */
/*  **str : Address of the pointer to  the string to append to digit          */
/*  *pos  : The lenght of the string that holds the integer.                  */
/*                                                                            */
/* RETURNS                                                                    */
/*  Nothing, but worths to be aware that thru **str there is communication    */
/*  with the calling function.                                                */
/*                                                                            */
/* OPERATES                                                                   */
/*  Treates diferently accordingly to integer's sign.                         */
/*                                                                            */
/*  When the integer has more than one digit, reduce integer size dividing    */
/*  by 10.                                                                    */
/*                                                                            */
/*  When the integer has one digit (n <= 9), calculate his ascii char.        */
/*                                                                            */
/*                         num = 48 + n % 10                                  */
/*                                                                            */
/*  When n is INT_MIN (-2147 483 648) the required sign change happens in     */
/*  the result of the modulo operation. I wait to change the sign when the    */
/*  integer is small.                                                         */
/*                                                                            */
/*             ----------------------------------------                       */
/*                         num = 48 + (-n % 10)                               */
/*  That does not work with INT_MIN                                           */
/*                                                                            */
/*  Recursively the function extract the less significant figure from the int */
/*  in such a way the figure is inserted in the string from the right to the  */
/*  left, from n towards zero index. Then in each recursive call we have to   */
/*  decrease the position where to insert the figure (pos -1)                 */
/*                                                                            */

static void	aux_ltoa(long n, char **str, int pos)
{
	char	num;

	if (0 < n)
	{
		if (9 < n)
			aux_ltoa(n / 10, str, pos - 1);
		num = 48 + n % 10;
	}
	else
	{
		if (n < -9)
			aux_ltoa(n / 10, str, pos - 1);
		num = n % 10;
		num = 48 - num;
	}
	str[0][pos] = num;
}

/* ft_itoa() allocates (with malloc(3)) and returns a strings representing    */
/* the integer received as an argument.                                       */
/* Negative numbers must be handlepointer                                .    */
/*                                                                            */
/* GETS                                                                       */
/*  n: the integer to convert                                                 */
/*                                                                            */
/* RETURNS                                                                    */
/*   The string representing the intege                                       */
/*   NULL if memory allocation fails.                                         */
/*                                                                            */
/* OPERATION                                                                  */
/*  Starts creating an empty (filled wiht spaces) string of enought lenght    */
/*  to hold all figures in the integer.                                       */
/*                                                                            */
/*  When n = 0 add a '0' to the empty string n the position 0 of a string of  */
/*  length 1.                                 */
/*                                                                            */
/*  When n is positive convert the integer into string                        */
/*                                                                            */
/*  When n is negative convert the integer into string and add '-' to head    */
/*                                                                            */
/* PROBLEMS I GOT                                                             */
/* I complicated my life with an approach to allocate memory for the string   */
/* representing the integer gradually as new digits are required. You can see */
/* it in this repository in ft_itoa_one_by_one.c                              */
/*                                                                            */
/* As i did not manage to pass the fsoares test ft_itoa(0), then i figured    */
/* out this other approach i can call ft_itoa_all_at_once.c                   */
/*                                                                            */
/* I learn to deal with a pointer passed by reference to a function           */

char	*ft_ltoa(long n, int *pos)
{
	char	*str;

	str = allocate_space_for(n, pos);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n > 0)
		{
			aux_itoa(n, &str, *pos);
		}
		if (n < 0)
		{
			aux_itoa(n, &str, *pos);
			str[0] = '-';
		}
	}
	return (str);
}
/*
int	main(void)
{
	long			i;
	int				i_len;
	char			*i_txt;
	struct timeval	a;
	long				num;

	i = 0;
	gettimeofday(&a, NULL);
	num = (a.tv_sec * 1000000 + a.tv_usec) / 1000;
	printf("%ld\n", num);
	while (i <= 10)
	{
		i_txt = ft_ltoa(num + i++, &i_len);
		printf(">%s< %d\n", i_txt, i_len);
	}
	return (0);
}*/
static char	*make_timestamp(int *ms_len, long sim_init_ms)
{
	struct timeval	t;
	long			now_ms;
	long			timestamp_ms;
	char			*ms;

	gettimeofday(&t, NULL);
	now_ms = (t.tv_sec * 1000000 + t.tv_usec) / 1000 ;
	timestamp_ms = now_ms - sim_init_ms;
	ms = ft_ltoa(timestamp_ms, ms_len);
	return (ms);
}

static long	make_timestamp2(int *ms_len, long sim_init_ms)
{
	struct timeval	t;
	long			now_ms;
	long			timestamp_ms;
	char			*ms;

	gettimeofday(&t, NULL);
	now_ms = (t.tv_sec * 1000000 + t.tv_usec) / 1000 ;
	return (now_ms - sim_init_ms);
}

int	philo_msg(char *msg, int msg_len, int mynum)
{
	char			*ms;
	int				ms_len;
	char			*me;
	int				me_len;

	ms = make_timestamp(&ms_len, 0);
	me = ft_itoa(mynum, &me_len);
	write(1, &ms[1], ms_len);
	write(1, me, me_len + 1);
	write(1, msg, msg_len);
	free(me);
	free(ms);
	return (0);
}

int	main(void)
{
	int	i;
	int	ms_len;

	i = 0;
	while (i < 100000)
	{
		i++;
		//philo_msg(" is eating\n", 11, 3);
		printf("%ld %d%s", make_timestamp2(&ms_len,0), 3," is eating\n" );
	}
	return (0);
}
