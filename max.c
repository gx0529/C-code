#include<stdio.h>

int main ()
{
	int a[10];
	int i = 0, max = 0;
	printf("������ʮ��������");
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
	printf("��ʮ�������е����ֵΪ��%d\n",max);
 	return 0;
}