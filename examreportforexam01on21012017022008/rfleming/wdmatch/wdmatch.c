/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:30:57 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 21:58:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	char	new;
	int i;
	int j;

	new = '\n';
	i = 0;
	j = 0;
	if (argc != 3)
		write (1, &new, 1);
	else
		while (argv[2][j] != '\0')
		{
			while (argv[1][i] != '\0')
			{
				if (argv[2][j] == argv[1][i])
				{
					i++;
					j++;
				}
				else j++;
			}
			j++;
		}
	if (i < ft_strlen(argv[1]))
		write (1, &new, 1);
	else
		i = 0;
		while (argv[1][i] != '\0')
		{
			write (1, &argv[1][i], 1);
			i++;
		}
	write (1, &new, 1);
	return (0);
}
