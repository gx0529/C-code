#include <stdio.h>

int main ()
{
	int a,b,c;
	int m1,m2;
	for(a=1; a<=9; a++)
		for(b=0; b<=9; b++)
			for(c=0; c<=9; c++)
			{
                m1=100*a+10*b+c;
	            m2=a*a*a+b*b*b+c*c*c;
	            if(m1 == m2)
				{
		            printf("m1=%d\t",m1);
				}
			}
	return 0;
}