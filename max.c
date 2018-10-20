#include<stdio.h>

int main ()
{
	int a[10];
	int i = 0, max = 0;
	printf("请输入十个整数：");
	for(i=0; i<=9; i++)
	{
		scanf("%d",&a[i]);
	}
    max=a[0];
	for(i=0; i<=9; i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	printf("这十个整数中的最大值为：%d\n",max);
 	return 0;
}