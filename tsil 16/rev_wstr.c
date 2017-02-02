/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 18:58:51 by exam              #+#    #+#             */
/*   Updated: 2015/07/17 19:24:53 by exam             ###   ########.fr       */
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

int		count_nb_word(char *str)
{
	int i;
	int nb_mot;

	i = 0;
	nb_mot = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			nb_mot += 1;
		i++;
	}
	return (nb_mot);
}

void	print_last(char *str, int word_to_get)
{
	int i;
	int word_so_far;

	word_so_far = 1;
	i = 0;
	while (str[i] && word_to_get != word_so_far)
	{
		if (str[i] == ' ')
			word_so_far += 1;
		i++;
	}
	while (str[i] && str[i] != ' ')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int nb_word;

	if (argc != 2)
	{
		ft_putstr("\n");
		return (0);
	}
	nb_word = count_nb_word(argv[1]);
	while (nb_word > 0)
	{
		print_last(argv[1], nb_word);
		if (nb_word > 1)
			ft_putstr(" ");
		nb_word--;
	}
	ft_putstr("\n");
	return (0);
}
