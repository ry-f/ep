/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:42:14 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 11:30:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strdup(char *src)
{
	char		*result;
	int			i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (i >= 0)
	{
		result[i] = src[i];
		i--;
	}
	return (result);
}

int				intcmp(char *a, char *b)
{
	while (*a == *b)
	{
		if (*a > '9' || *a < '0')
			return (1);
		a++;
		b++;
	}
	return ((*a > '9' || *a < '0') && (*b < '0' || *b > '9'));
}
