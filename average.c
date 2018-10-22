
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int average = 0;
	printf("请输入两个数：");
	scanf("%d%d",&a, &b);
	average = a+(b-a)/2;
	printf("average=%d\n",average);
	return 0;
}
