#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		atoi(char *str)
{
	int	res = 0;;
	int	i = 0;

	if (str[0] == '+')
		i = 1;
	while (str[i]) 
		res = res * 10 + str[i++] - '0';
	return (res);
}

void	putnbr(int nb)
{
	if (nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		is_prime(int nb)
{
	int	i = 3;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	sum = 0;
	int	i = 0;
	int	nb;

	if (ac != 2 || av[1][0] == '-')
	{
		putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	nb = atoi(av[1]);
	while (i <= nb)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	putnbr(sum);
	ft_putchar('\n');
	return (0);
}
