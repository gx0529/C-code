#include <stdio.h>

int main()
{
	int i=0;
	for(i=1000; i<=2000; i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0))
			printf("%d\t",i);
	}
	return 0;
}