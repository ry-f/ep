/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:02:58 by exam              #+#    #+#             */
/*   Updated: 2017/01/27 18:31:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	char	a;
	char	new;
	int		i;
	
	a = 'a';
	new = '\n';
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'a')
			{
				write (1, &a, 1);
				write (1, &new, 1);
				return (0);
			}
			else
				i++;
		}
		write (1, &new, 1);
		return (0);
	}
	else
	{
		write (1, &a, 1);
		write (1, &new, 1);
		return (0);
	}
}
