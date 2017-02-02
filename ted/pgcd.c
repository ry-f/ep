/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:36:52 by exam              #+#    #+#             */
/*   Updated: 2015/12/08 11:23:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		pgcd(int a, int b)
{
	int	result;

	if (a == b)
		return (a);
	result = (a > b) ? b : a;
	while (result != 1)
	{
		if ((a % result) == 0 && (b % result) == 0)
			return (result);
		result--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	a = atoi(av[1]);
	b = atoi(av[2]);
	printf("%i\n", pgcd(a, b));
}
