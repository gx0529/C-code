#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

char* my_strcpy(char *dest,const char *src)
{
	char *ret = dest;
	assert(dest!=NULL);
	assert(src!=NULL);
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
	char arr[20]={0};
	my_strcpy(arr,"hello world");
	printf("%s\n",arr);
	return 0;
}
