/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_union.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:53:09 by exam              #+#    #+#             */
/*   Updated: 2017/01/27 21:33:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		included(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	new;
	char	c;
	char	*s1;
	char	*s2;
	char	*sub1;
	char	*sub2;
	int		i;

	new = '\n';
	if (argc != 3)
	{
		write (1, &new, 1);
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	sub1 = "";
	sub2 = "";
	i = 1;
	c = s1[0];
	sub1[0] = s1[0];
	write(1, &c, 1);
	while (*s1)
	{
		c = s1[i];
		if (included(sub1, c))
			i++;
		else
		{
			write(1, &c, 1);
			sub1[i] = s1[i];
			i++;
		}
	}
	*i = 1;
	sub2[0] = s2[0];
	while (*s2)
	{
		c = s2[i]
		if (included(s1, s2[i]))
			i++;
		else if (included(s1, s2[i]))
			i++;
		else
		{
			c = s2[i];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, &new, 1);
	return (0);
}
