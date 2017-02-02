/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:33:06 by tuardoui          #+#    #+#             */
/*   Updated: 2015/11/24 14:04:53 by tuardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	int		x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	*ft_strrev(char *str)
{
	int i;
	int j;
	char x;

	i = 0;
	j = ft_strlen(str) -1;
	while (i < j)
	{
		x = str[i];
		str[i] = str[j];
		str[j] = x;
		i++;
		j--;
	}
	return (str);
}

