#include<stdio.h>
//#include<String.h>
int main()
{
	int a[5]={ 4 , 5 , 3 , 7 , 8 } ;
	int b[5]={ 2 , 6 , 10 , 12 , 9 } ;
	int t ;
	int i ;
	for(i=0 ; i<5 ; i++ )
	{
		int t = a[i] ;
		a [i] = b[i] ;
		b [i] = t ;
	}
	printf("������a����Ϊ��\n");
	for(i=0 ; i<5 ; i++ )
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("������b����Ϊ��\n");
	for(i=0 ; i<5 ; i++ )
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}
