/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:36:02 by exam              #+#    #+#             */
/*   Updated: 2017/01/27 21:46:43 by exam             ###   ########.fr       */
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
	int		i;
	char	c;
	char	*already;

	i = 0;
	new = '\n';
	already = "";
	if (argc != 3)
	{
		write(1, &new, 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (included(argv[2], argv[1][i]))
		{
			if (!included(already, argv[1][i]))
				c = argv[1][i];
				included += c;
				write(1, &c, 1);
				i++;
		}
		else
			i++;
	}
	write(1, &new, 1);
	return (0);
}
