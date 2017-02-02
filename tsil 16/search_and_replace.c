/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 17:09:13 by exam              #+#    #+#             */
/*   Updated: 2015/07/17 17:34:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char a, char b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			ft_putchar(b);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		get_size(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	if ((get_size(argv[2]) != 1) || (get_size(argv[3]) != 1))
	{
		ft_putchar('\n');
		return (0);
	}
	search_and_replace(argv[1], argv[2][0], argv[3][0]);
	ft_putchar('\n');
	return (0);
}
