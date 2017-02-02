/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:25:10 by exam              #+#    #+#             */
/*   Updated: 2015/12/08 12:07:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char *str)
{
	int		result;
	
	result = 0;
	while (*str)
	{
		if (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		else
		{
			result += 1;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	return (result);
}

static char		*alloc_word(char *str)
{
	int		l;
	char	*word;
	int		i;

	l = 0;
	while (str[l] && str[l] != ' ' && str[l] != '\n' && str[l] != '\t')
		l++;
	word = (char *)malloc(l + 1);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char *str)
{
	char	**tab;
	int		nb_words;
	int		i;

	nb_words = count_words(str);
	tab = (char**)malloc(sizeof(*tab) * (nb_words + 1));
	i = 0;
	while (*str)
	{
		if (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		else
		{
			tab[i] = alloc_word(str);
			i++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}
