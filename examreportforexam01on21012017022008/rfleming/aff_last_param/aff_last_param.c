/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:59:20 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 20:13:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argv, char **argc)
{
	char	new;
	char	end;
	int		i;
	int		j;

	new = '\n';
	end = '\0';
	if (argv < 2)
		write (1, &new, 1);
	else
	{
		i = 0;
		j = argv - 1;
		while (argc[j][i] != '\0')
		{
			write (1, &argc[j][i], 1);
			i++;
		}
		write (1, &new, 1);
		return (0);
	}
}
