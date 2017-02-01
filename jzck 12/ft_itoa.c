/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 19:34:47 by exam              #+#    #+#             */
/*   Updated: 2016/08/25 18:15:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(x) (x < 0 ? -x : x)

char	*ft_itoa(int nbr)
{
	char	*res;
	char	*start;
	long	pow;
	int		len;

	len = 1;
	pow = 1;
	while (nbr >= pow * 10)
	{
		pow *= 10;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 10));
	start = res;
	if (nbr < 0)
	{
		*res = '-';
		res++;
	}
	while (pow)
	{
		*res = ABS(nbr / pow) + '0';
		nbr = ABS(nbr % pow);
		pow /= 10;
		res++;
		len--;
	}
	*res = '\0';
	return (start);
}

#include <stdio.h>
int		main()
{
	int	nb = -2147483648;
	printf("%s\n", ft_itoa(nb));
}
