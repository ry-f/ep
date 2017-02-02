/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 19:54:22 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 20:17:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_printdes(unsigned int x)
{
	unsigned int i;
	unsigned int aux;

	i = 2;
	aux = x;
	while (i < (x / 2))
	{
		if (aux % i == 0 && aux != i)
		{
			printf("%d*", i);
			aux = aux / i;
		}
		else if (aux == i)
		{
			printf("%d", i);
			i++;
		}
		else
			i++;
	}
}

int		ft_nrprime(unsigned int x)
{
	unsigned int	i;
	int				ok;

	i = 2;
	ok = 1;
	while (i < (x / 2))
	{
		if (x % i == 0)
			ok = 0;
		i++;
	}
	return (ok);
}

int		main(int argc, char **argv)
{
	unsigned int	x;
	int				ok;

	if (argc != 2)
		printf("\n");
	else
	{
		x = atoi(argv[1]);
		ok = ft_nrprime(x);
		if (ok == 1)
			printf("%d", x);
		else
			ft_printdes(x);
		printf("\n");
	}
	return (0);
}

/*
Exercitiu : fprime
Fisiere de iesire   : fprime.c
Functii autorizate : printf, atoi
--------------------------------------------------------------------------------

Scrieti un program ce ia ca parametru un intreg strict pozitiv si care va afisa 
descompunerea in factori primi la iesirea standard, urmat de un '\n'.

Factorii trebuie sa fie afisati in ordine crescatoare si separati de '*', 
astfel incat expresia afisata sa dea rezultatul corect.

Daca numarul de parametri este diferit de 1, programul va afisa '\n'.

Parametrul de intrare, cand este transmis, va fi totdeauna un numar valid 
fara caractere neconforme.

Exemplu:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/