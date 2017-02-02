#include <unistd.h>

#include <math.h>

int main(void)
{
	char lstnbr[25];
	char ltr;
	char rtn;
	rtn = '\n';
	ltr=122;
	lstnbr[0]=122;

	while (ltr >= 97)
	{
		if ( ltr%2 == 0)
		{
			lstnbr[122-ltr]=ltr;
			write(1,&lstnbr[122-ltr],1);
		}
		else
		{
			lstnbr[122-ltr]=ltr-32;
			write(1,&lstnbr[122-ltr],1);
		}
		ltr--;
	}
	write(1, &rtn, 1);
	return 0;
}
