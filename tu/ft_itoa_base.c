// wtf
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int converted_number[64];
	int i = 0;
	int n;
	char *result;

	n = value;
	if (value < 0)
		value = value * -1;
	while (value != 0)
	{
		converted_number[i] = value % base;
		value = value / base;
		++i;
	}
	--i;
	result = malloc(i * sizeof(char));
	if (n < 0)
	{
		result[0] = '-';
		n = 1;
	}
	while (i >= 0)
	{
		result[n] = base_digits[converted_number[i]];
		i--;
		n++;
	}
	return (result);
}
