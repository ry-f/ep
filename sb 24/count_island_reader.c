/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:18:37 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:52:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			read_first_line(int fd, char **r)
{
	int		i = 0;

	r[0] = malloc(sizeof(char) * 1300);
	while (read(fd, r[0] + i, 1) > 0)
	{
		if (r[0][i] == '\n')
		{
			r[0][i] = 0;
			return (i);
		}
		else if (r[0][i] != '.' && r[0][i] != 'X')
			return (-1);
		i++;
	}
	return (-1);
}

int			read_one_line(int fd, int len, char **r)
{
	int		readed;

	*r = malloc(sizeof(char) * (len + 10));
	readed = read(fd, *r, len + 1);
	if (readed == -1)
		return (-1);
	if (readed == 0)
		return (0);
	if (readed == 1 && **r == '\n')
	{
		**r = 0;
		return (0);
	}
	if (readed < len)
		return (-1);
	if (r[0][len] != '\n')
		return (-1);
	r[0][len] = 0;
	readed -= 2;
	while (readed >= 0)
	{
		if (r[0][readed] != 'X' && r[0][readed] != '.')
			return (-1);
		readed--;
	}
	return (1);
}

char		**cread(int fd)
{
	char	**result;
	int		i;
	int		linelen;
	int		ret;
	
	result = malloc(sizeof(char *) * 100000);
	i = 0;
	linelen = read_first_line(fd, result);
	if (linelen < 1)
		return (0);
	i++;
	while (1)
	{
		ret = read_one_line(fd, linelen, result + i);
		if (ret == -1)
			return (0);
		if (ret == 0)
			break;
		i++;
	}
	return (result);
}
