/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:35:27 by exam              #+#    #+#             */
/*   Updated: 2016/12/13 11:41:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
	long	tmp;
	int		len;
	char	*answer;
	char	*key = "0123456789ABCDEF";

	tmp = value;
	len = 0;
	if (tmp == 0)
	{
		answer = (char *)malloc(sizeof(char) * 2);
		answer[0] = '0';
		answer[1] = '\0';
		return (answer);
	}
	if (tmp < 0 && (base == 10))
		len++;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / base;
	}
	tmp = value;
	answer = (char *)malloc(sizeof(char) * (len + 1));
	answer[len] = '\0';
	len--;
	if (tmp < 0 && (base == 10))
	{
		answer[0] = '-';
		tmp = tmp * -1;
	}
	else if (tmp < 0)
		tmp = tmp * -1;
	while (tmp != 0)
	{
		answer[len] = key[(tmp % base)]; 
		tmp = tmp / base;
		len--;
	}
	return (answer);

}
