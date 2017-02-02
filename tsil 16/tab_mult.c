/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 18:00:58 by exam              #+#    #+#             */
/*   Updated: 2015/07/17 18:56:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		get_number_from_str(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb);
}

void	print_result(int res)
{
	int new_nb;
	int i;

	new_nb = 0;
	while (res > 0)
	{
		new_nb *= 10;
		new_nb += res % 10;
		res /= 10;
	}
	while (new_nb > 0)
	{
		i = (new_nb % 10) + 48;
		write(1, &i, 1);
		new_nb /= 10;
	}
}

void	write_solution(char *str, int nb)
{
	int i;
	int res;

	i = 1 + 48;
	while (i < 10 + 48)
	{
		write(1, &i, 1);
		ft_putstr(" x ");
		ft_putstr(str);
		ft_putstr(" = ");
		res = (i - 48) * nb;
		print_result(res);
		ft_putstr("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	int nb;

	if (argc != 2)
	{
		ft_putstr("\n");
		return (0);
	}
	nb = get_number_from_str(argv[1]);
	write_solution(argv[1], nb);
}
