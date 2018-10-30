#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

char* my_strcat(char *dest,const char *src)
{
	char *ret = dest;
	assert(dest!=NULL);
	assert(src!=NULL);
    while(*dest)
	{
		dest++;
	}
	while(*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return ret;
}
int main()
{
	char arr[20]="hello ";
	my_strcat(arr,"world");
	printf("%s\n",arr);
	return 0;
}
