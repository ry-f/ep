/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:49:19 by exam              #+#    #+#             */
/*   Updated: 2016/01/19 12:29:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int				ft_isprintable(unsigned char c)
{
	if (c <= 32 || c >= 127)
		return (0);
	else
		return (1);
}

void			ft_puthex(int n)
{
	if (n >= 16)
		ft_puthex(n / 16);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + 48);
	else
		ft_putchar((n % 16) - 10 + 97);
}

void			print_chars(unsigned char *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_isprintable(tab[i]))
			ft_putchar(tab[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void			print_memory(const void *addr, size_t size)
{
	unsigned char	*tab;
	size_t			i;
	int				end_line;
	int				lines;
	int				j;

	end_line = 1;
	lines = 0;
	tab = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (tab[i] == 0)
			ft_putstr("00");
		else if (tab[i] < 16)
		{
			ft_putchar('0');
			ft_puthex(tab[i]);
		}
		else
			ft_puthex(tab[i]);
		if (i != 0 && i % 2 != 0)
			ft_putchar(' ');
		if (end_line == 16)
		{
			print_chars(tab + (lines * 16), 16);
			end_line = 0;
			lines++;
		}
		end_line++;
		i++;
	}
	i = size - (lines * 16);
	if (i > 0)
	{
		j = i;
		while (j++ < 16)
		{
			if (j % 2 != 0)
				ft_putchar(' ');
			ft_putstr("  ");
		}
		print_chars(tab + (lines * 16), i);
	}
}
