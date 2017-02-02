/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:51:09 by exam              #+#    #+#             */
/*   Updated: 2016/12/13 10:54:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_ascii(unsigned const char *address, int len)
{
	unsigned const char *a2;
	int i;

	i = 0;
	a2 = (address - len);
	while (i < len)
	{
		if ((32 < *a2) && (*a2 < 127))
			ft_putchar(*a2);
		else
			ft_putchar('.');
		a2++;
		i++;
	}
	ft_putchar('\n');
}

void print_memory(const void *addr, size_t size)
{
	unsigned const char *address;
	size_t i;
	char *key = "0123456789abcdef";
	size_t j;

	i = 0;
	j = 0;
	address = (unsigned const char *)addr;
	while (i < size)
	{	
		ft_putchar(key[((*address)/16)]);
		ft_putchar(key[((*address) % 16)]);
		address++;
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0)
			print_ascii(address, 16);
	}
	if (!(i % 16 == 0))
	{
		while (((i % 16) + j) < 16)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			j++;
			if ((i + j) % 2 == 0)
				ft_putchar(' ');
		}
		print_ascii(address, (i % 16));
	}
}
