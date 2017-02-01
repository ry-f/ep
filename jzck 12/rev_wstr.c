#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_count_words(char *str)
{
	int	i = 1;

	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

void	ft_print_to_space(char *str)
{
	while (*str != ' ' && *str != '\0')
		ft_putchar(*str++);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	*buf;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = ft_count_words(av[1]);
	while (i)
	{
		j = 1;
		buf = av[1];
		while (i != j)
		{
			if (*buf == ' ')
				j++;
			buf++;
		}
		ft_print_to_space(buf);
		if (i != 1)
			ft_putchar(' ');
		i--;
	}
	ft_putchar('\n');
	return (0);
}

