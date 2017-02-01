#include "unistd.h"

int		only_a(void);
{
	char	c;
	c = 'a';

	write(1, c, 1);
	return(0);
}
