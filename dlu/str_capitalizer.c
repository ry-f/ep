/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 18:07:07 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 19:46:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_lit(char **argv, int i, int j)
{
	if ((argv[i][j] >= 'a') && (argv[i][j] <= 'z'))
		return (0);
	if ((argv[i][j] >= 'A') && (argv[i][j] <= 'Z'))
		return (0);
	return (1);
}

void	ft_int_word(char **argv, int i, int j)
{
	if ((argv[i][j] >= 'a') && (argv[i][j] <= 'z'))
		ft_putchar(argv[i][j]);
	else if ((argv[i][j] >= 'A') && (argv[i][j] <= 'Z'))
		ft_putchar(argv[i][j] + 32);
	else if (argv[i][j] != ' ')
		ft_putchar(argv[i][j]);
}

int		ft_print_word(char **argv, int i, int j)
{
	if (((argv[i][j] >= 'a') && (argv[i][j] <= 'z')
			&& (argv[i][j - 1] == ' ')) || ((j == 0)
			&& (argv[i][j] >= 'a') && (argv[i][j] <= 'z')))
	{
		ft_putchar(argv[i][j] - 32);
		j++;
	}
	else if (((argv[i][j] >= 'A') && (argv[i][j] <= 'Z')
			&& (argv[i][j - 1] == ' ')) || ((j == 0)
			&& (argv[i][j] >= 'A') && (argv[i][j] <= 'Z')))
	{
		ft_putchar(argv[i][j]);
		j++;
	}
	while (!(ft_lit(argv, i, j)))
	{
		ft_int_word(argv, i, j);
		j++;
	}
	return (j);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_lit(argv, i, j))
			{
				ft_putchar(argv[i][j]);
				j++;
			}
			else
				j = ft_print_word(argv, i, j);
		}
		i++;
		ft_putchar('\n');
	}
	if (argc == 1)
		ft_putchar('\n');
	return (0);
}

/*
Exercitiu  : str_capitalizer
Fisiere de iesire   : str_capitalizer.c
Functii autorizate : write
--------------------------------------------------------------------------------

Scrieti un program ce ia ca parametru unul sau mai multe siruri de caractere si 
care pentru fiecare argument transforma primul caracter al fiecarui cuvant (daca 
e vorba de o litera, evident) in majuscule iar restul cuvantului il transforma 
in minuscule si afiseaza resultatul la iesirea standard, urmat de '\n'.

Numim "cuvant" o portiune dintrun sir de caractere delimitat fie de spatii si/sau 
tabulatoare, fie de inceputul/sfarsitul sirului. Daca un cuvant este compus dintr-o 
singura litera, ea va trebui transformata in majuscula.

Daca nu exista nici un parametru, programul va afisa '\n'.

Exemplu:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>
*/