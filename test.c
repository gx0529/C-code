#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int t = 0;
	printf("������������:");
	scanf("%d,%d,%d", &a, &b, &c);
    if(a<b)
	{
		t = b;
		b = a;
		a = t;
	}
    if(a<c)
	{
		t = c;
		c = a;
		a = t;
	}
	if(b<c)
	{
		t = c;
		c = b;
		b = t;
	}
	printf("���������Ӵ�С��˳��Ϊ��");
	printf("%d,%d,%d\n",a,b,c);
	return 0;
}