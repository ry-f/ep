/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:23:13 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 18:01:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (0);
	else
		return (1);
}

int		ft_count(char c)
{
	int k;

	k = (c - 'a');
	return (k);
}

void	ft_print(char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[1][i])
	{
		if (ft_is_alpha(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
		}
		else
		{
			while (j <= ft_count(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				j++;
			}
			j = 0;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_print(argv);
	write(1, "\n", 1);
	return (0);
}

/*
Exercitiu  : repeat_alpha
Fisiere de iesire  : repeat_alpha.c
Functii autorizate : write
--------------------------------------------------------------------------------

Scrieti un program numit repeat_alpha care primeste un sir de caractere si il
afiseaza repetand fiecare caracter alfabetic de atatea ori cat indexul sau
alfabetic, urmat de un '\n'.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Majusculele raman neschimbate.

Daca numarul de argumente nu e 1, programul afiseaza '\n'.

Exemple:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/