/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/11 18:14:56 by exam              #+#    #+#             */
/*   Updated: 2014/07/11 18:21:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	rot_char(char c)
{
	if (c == 'Z')
		return ('A');
	else if (c == 'z')
		return ('a');
	return (c + 1);
}

void	ft_rotone(char *str)
{
	while (*str)
	{
		if (is_alpha(*str))
			ft_putchar(rot_char(*str));
		else
			ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}
