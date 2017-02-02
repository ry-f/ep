/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:15:30 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 09:34:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			blankstrlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

char		ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

int			mstrcmp(char *a, char *b)
{
	while (*a && *b && ft_toupper(*a) == ft_toupper(*b))
	{
		a++;
		b++;
	}
	return (ft_toupper(*a) - ft_toupper(*b));
}

char		*get_first(char *src)
{
	int		sizemin;
	char	*min;
	int		i;

	sizemin = 1000000;
	min = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && src[i] == ' ')
			i++;
		if (!src[i])
			break;
		if (blankstrlen(src + i) < sizemin)
		{
			min = src + i;
			sizemin = blankstrlen(src + i);
		}
		else if (blankstrlen(src + i) == sizemin)
		{
			if (mstrcmp(src + i, min) < 0)
			{
				min = src + i;
				sizemin = blankstrlen(src + i);
			}
		}
		while (src[i] && src[i] != ' ')
			i++;
	}
	return (min);
}

int			conti(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (1);
		s++;
	}
	return (0);
}

void		erase(char *s)
{
	while (*s)
	{
		if (*s == ' ')
			return ;
		*s = ' ';
		s++;
	}
}

int			main(int ac, char **av)
{
	char	*min;
	int		lastlen;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	lastlen = -1;
	while (conti(av[1]))
	{
		min = get_first(av[1]);
		if (lastlen != -1 && lastlen != blankstrlen(min))
			write(1, "\n", 1);
		else if (lastlen != -1)
			write(1, " ", 1);
		lastlen = blankstrlen(min);
		write(1, min, lastlen);
		erase(min);
	}
	write(1, "\n", 1);
	return (0);
}
