#include "unistd.h"

int		only_z(void)
{
	char	c;
	c = 'z';

	write(1, c, 1);
	return(0);
}
