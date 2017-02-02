/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 10:00:44 by exam              #+#    #+#             */
/*   Updated: 2015/04/01 10:10:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	char	stack[2048];
	int		i;
	int		inst;
	int		ptr;

	i = 2047;
	while (i >= 0)
		stack[i--] = 0;
	if (ac == 2)
	{
		ptr = 0;
		inst = 0;
		while (av[1][inst])
		{
			if (av[1][inst] == '>')
				ptr++;
			else if (av[1][inst] == '<')
				ptr--;
			else if (av[1][inst] == '+')
				stack[ptr]++;
			else if (av[1][inst] == '-')
				stack[ptr]--;
			else if (av[1][inst] == '.')
				write(1, stack + ptr, 1);
			else if (av[1][inst] == '[')
			{
				if (stack[ptr] == 0)
				{
					i = 0;
					inst++;
					while (av[1][inst])
					{
						if (av[1][inst] == '[')
							i++;
						if (av[1][inst] == ']' && i == 0)
							break;
						else if (av[1][inst] == ']')
							i--;
						inst++;
					}
				}
			}
			else if (av[1][inst] == ']')
			{
				if (stack[ptr] != 0)
				{
					i = 0;
					inst--;
					while (inst > 0)
					{
						if (av[1][inst] == ']')
							i++;
						if (av[1][inst] == '[' && i == 0)
							break;
						else if (av[1][inst] == '[')
							i--;
						inst--;
					}
				}
			}
			inst++;
		}
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
