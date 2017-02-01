#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	char *nl = "\n";
	char *s1;
	char *s2;

	if (ac != 3)
	{
		write(1, nl, 1);
		return (0);
	}
	s1 = av[1];
	s2 = av[2];
	while (*s2)
	{
		if (*s1 == *s2)
			s1++;
		if (!*s1)
		{
			write(1, av[1], ft_strlen(av[1]));
			write(1, nl, 1);
			return (0);
		}
		s2++;
	}
	write(1, nl, 1);
	return (0);
}
