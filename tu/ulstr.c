#include <unistd.h>

void	ulstr(char *s)
{
	char	c;

	while (*s)
	{
	if (*s >= 'a' && *s <= 'z')
	c = *s - 32;
	else if (*s >= 'A' && *s <= 'Z')
	c = *s + 32;
	else
	c = *s;
	write(1, &c, 1);
	s++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
