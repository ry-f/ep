/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 17:38:08 by exam              #+#    #+#             */
/*   Updated: 2015/07/17 17:58:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		seen_before(char *str, char to_find, int max_pos)
{
	int i;

	i = 0;
	while (str[i] && i < max_pos)
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		j = 0;
		if (seen_before(str1, str1[i], i))
		{
			i++;
			continue;
		}
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				ft_putchar(str1[i]);
				break ;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
