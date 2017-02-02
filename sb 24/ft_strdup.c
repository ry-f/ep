/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/18 19:35:52 by exam              #+#    #+#             */
/*   Updated: 2014/07/18 19:39:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int		i;
	char	*result;

	i = 0;
	while (src[i])
		i++;
	i++;
	if (!(result = malloc(sizeof(char) * i)))
		return (NULL);
	while (i >= 0)
	{
		result[i] = src[i];
		i--;
	}
	return (result);
}
