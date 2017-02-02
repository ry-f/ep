/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 18:44:11 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 19:19:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strstr(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s2[i] == s1[j])
			j++;
		i++;
	}
	if (j == ft_strlen(s1))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	char c;
	char c1;

	c = '1';
	c1 = '0';
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strstr(argv[1], argv[2]))
	{
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, &c1, 1);
		write(1, "\n", 1);
	}
	return (0);
}

/*
Exercitiu  : hidenp
Fisiere de iesire   : hidenp.c
Functii autorizae : write
--------------------------------------------------------------------------------

Scrieti un program numit hidenp ce ia ca parametru doua siruri de caractere si 
care afiseaza 1 urmat de '\n' daca primul sir este inclus in cel de-al doilea. 
In caz contrar se va afisa 0 urmat de '\n'.

Fie s1 si s2 doua siruri de caractere. Spunem ca sirul s1 este inclus in sirul 
s2 daca putem gasi fiecare caracter al sirului s1 in s2 si acestea sa fie in 
aceeasi ordine ca in sirul s1. Mai mult, sirul vid este inclus in orice sir.

Daca numarul de parametri transmis este diferit de 2, programul vaafisa '\n'.

Exemple :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/