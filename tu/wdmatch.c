#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	i++;
	return (i);
}

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
	if (s2[i] && s1[j] && s1[j] == s2[i])
	j++;
	i++;
	}
	if (!s1[j])
	write(1, s1, ft_strlen(s1));
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
