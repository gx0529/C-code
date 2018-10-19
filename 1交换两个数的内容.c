#include <stdio.h>

int main ()
{
	int a = 3;
	int b = 5;
	printf("a=%d\tb=%d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d\tb=%d\n",a,b);
	return 0;
}
