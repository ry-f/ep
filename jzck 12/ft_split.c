/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 20:02:19 by exam              #+#    #+#             */
/*   Updated: 2016/08/25 13:01:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SEP(x) (x == ' ' || x == '\t' || x == '\n')

char	**alloc_table(char **table, char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (SEP(str[i]))
		str++;
	while (str[i])
	{
		if (SEP(str[i]))
		{
			while (SEP(str[i]))
				i++;
		}
		else
		{
			i++;
		}
		if (!SEP(str[i]) && (SEP(str[i + 1]) || !str[i + 1]))
		{
			j++;
		}
	}
	table = (char **)malloc(sizeof(char *) * (j + 2));
	table[j] = 0;
	return(table);
}

char	**alloc_words(char **table, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i])
	{
		if (SEP(str[i]))
		{
			k = 0;
			while (SEP(str[i]))
				i++;
		}
		else
		{
			k++;
			i++;
		}
		if (!SEP(str[i]) && (SEP(str[i + 1]) || !str[i + 1]))
		{
			table[j++] = (char *)malloc(sizeof(char) * (k + 10));
			k = 0;
		}
	}
	return (table);
}

char	**fill_table(char **table, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i])
	{
		if (SEP(str[i]))
		{
			k = 0;
			j++;
			while (SEP(str[i]))
				i++;
		}
		else
		{
			table[j][k] = str[i];
			k++;
			table[j][k] = '\0';
			i++;
		}
	}
	return (table);
}

char	**ft_split(char *str)
{
	char	**table;

	table = NULL;
	table = alloc_table(table, str);
	table = alloc_words(table, str);
	table = fill_table(table, str);
	return (table);
}
