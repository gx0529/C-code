#include <stdio.h>

int main ()
{
	int i = 0;
	int j = 0;
	for(i=1; i<=100; i++)
	{
		if(i%10==9)
		{
			j++;
		}
		if(i-i%10==90)
		{
			j++;
		}
	}
	printf("j=%d\n",j);
	return 0;
}