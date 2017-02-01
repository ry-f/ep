/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 18:09:09 by exam              #+#    #+#             */
/*   Updated: 2016/08/12 18:18:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	char nl;
	char *arg;

	nl = '\n';
	if (ac != 2)
	{
		write(1, &nl, 1);
		return (0);
	}
	arg = av[1];
	while (*arg)
	{
		if ((*arg >= 'a' && *arg < 'z') || (*arg >= 'A' && *arg < 'Z'))
			ft_putchar(*arg + 1);
		else if (*arg == 'z' || *arg == 'Z')
			ft_putchar(*arg - 25);
		else
			ft_putchar(*arg);
		arg++;
	}
	write(1, &nl, 1);
	return (0);
}
