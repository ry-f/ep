/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:28:39 by exam              #+#    #+#             */
/*   Updated: 2016/12/13 09:31:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa(int nbr)
{
	long	tmp;
	int		len;
	char	*answer;

	tmp = nbr;
	len = 0;
	if (tmp == 0)
	{
		answer = (char *)malloc(sizeof(char) * 2);
		answer[0] = '0';
		answer[1] = '\0';
		return (answer);
	}
	if (tmp < 0)
		len++;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	tmp = nbr;
	answer = (char *)malloc(sizeof(char) * (len + 1));
	answer[len] = '\0';
	len--;
	if (tmp < 0)
	{
		answer[0] = '-';
		tmp = tmp * -1;
	}
	while (tmp != 0)
	{
		answer[len] = ('0' + (tmp % 10));
		tmp = tmp / 10;
		len--;
	}
	return (answer);
}
