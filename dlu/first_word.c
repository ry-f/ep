/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:07:55 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 17:29:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_word(char **argv, int i)
{
	while (argv[1][i] != ' ' && argv[1][i])
	{
		ft_putchar(argv[1][i]);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	c;
	int		ok;
	int		i;

	c = '\n';
	if (argc != 2)
	{
		ft_putchar(c);
		return (0);
	}
	else if (argc == 2)
	{
		i = 0;
		ok = 0;
		while (argv[1][i] && ok == 0)
		{
			if (argv[1][i] != ' ')
				ok = ft_check_word(argv, i);
			i++;
		}
	}
	ft_putchar(c);
	return (0);
}

/*
Exercitiu  : first_word
Fisiere de iesire  : first_word.c
Functii autorizate : write
--------------------------------------------------------------------------------

Scrieti un program care ia ca parametru un sir de caractere si afiseaza primul 
cuvant din acest sir, urmat de un '\n'.

Numim "cuvant" o portiune a sirului de caractere delimitat de spatii sau/si 
tabulatori, atat la inceputul cat si la sfarsitul sirului.

Daca numarul de parametri transmis este diferit de 1, sau daca nu este niciun 
cuvant de afisat, programul va afisa \texttt'\n'.

Exemplu:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/