#include <unistd.h>

int	main()
{
	char *c = "9876543210\n";
	write(1, c, 11);
}
