#include <stdio.h>

int main ()
{
	int sign = 1;
	double i=2.0, sum=1.0, j;
	for(i=2.0;i<=100.0;i++)
	{
		sign = (-1) * sign;
		j = sign*(1/i);
		sum = j + sum;
	}
	printf("%lf\n",sum);
	return 0;
}
