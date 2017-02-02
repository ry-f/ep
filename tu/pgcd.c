#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char c;

	if (n / 10  > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int		ft_atoi(char *s)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (s[++i] && s[i] != '\n')
		total = total * 10 + s[i] - '0';
	return (total);
}

int		pgcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int		main(int ac, char **av)
{
	if (ac == 3)
	ft_putnbr(pgcd(ft_atoi(av[1]), ft_atoi(av[2])));
	write(1, "\n", 1);
}
