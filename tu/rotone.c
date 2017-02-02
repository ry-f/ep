#include <unistd.h>

void	rotone(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i])
	{
	c = str[i];
	if (c >= 'a' && c <= 'y')
	c = c + 1;
	else if (c == 'z')
	c = 'a';
	if (c >= 'A' && c <= 'Y')
	c = c + 1;
	else if (c == 'Z')
	c = 'A';
	write(1, &c, 1);
	i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}