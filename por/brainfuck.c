#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		in_list(char *list, char match)
{
	while (*list)
	{
		if (match == *list)
			return (1);
		list++;
	}
	
	return (0);
}

int main(int ac, char **av)
{
	char *empty_string;
	char *p;
	char *list = "><+-.[]";
	char *source;
	int count;
	int i;

	count = 0;
	i = 0;
	empty_string = (char *)malloc(sizeof(char) * 5000);
	p = empty_string;
	if (ac < 2)
	{
		ft_putstr("\n");		
		return (0);
	}
	source = av[1];
	while (*source)
	{
		if (in_list(list, *source))
		{

			if ((*source == '[') && (*p == 0))
			{
				while (*source != ']')
					source++;
			}
			else if ((*source == ']') && (*p != 0))
			{
				while (*source != '[')
					source--;
			}
			else if (*source == '>')
				p += 1;
			else if (*source == '<')
				p -=1;
			else if (*source == '+')
				*p +=1;
			else if (*source == '-')
				*p -=1;
			else if (*source == '.')
				ft_putchar(*p);
		}
		source += 1;
	}
	free(empty_string);
	return (0);
}

