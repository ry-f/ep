/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:11:42 by exam              #+#    #+#             */
/*   Updated: 2015/12/08 12:46:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long		ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

static char		*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}

static int		length_number(int val, int base)
{
	int		size;

	size = 1;
	while (ft_power(base, size) < val)
		size++;
	return (size);
}

char			*ft_itoa_base(int value, int base)
{
	char	*result;
	int		size;
	int		sign;
	int		i;

	sign = (value < 0) ? 1 : 0;
	value = (value < 0) ? -value : value;
	if (value == 0)
		return ("0");
	size = length_number(value, base);
	result = (char *)malloc(size + 1);
	i = 0;
	while (value > 0)
	{
		if (base >= 10 && (value % base) >= 10)
			result[i] = (value % base) - 10 + 65;
		else
			result[i] = (value % base) + 48;
		value /= base;
		i++;
	}
	if (sign)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
