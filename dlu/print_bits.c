/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:33:04 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 18:02:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 128;
	while (i > 0)
	{
		if (octet < i)
		{
			c = '0';
			i = i / 2;
			write(1, &c, 1);
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - i;
			i = i / 2;
		}
	}
}

/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Scrieti o functie care primeste un byte si afiseaza byte-ul in binar FARA LINIE NOUA LA SFARSTI.

Functia trebuie declarata ca si mai jos:

void	print_bits(unsigned char octet);

Exemplu, daca trimiteti 2 functiei print_bits, va afisa "00000010"
*/