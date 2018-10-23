#include <stdio.h>

int main()
{
	char password[10]={0};
	int i=0;
	int j=0;
	for(i=0; i<3; i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º");
		scanf("%s",password);
		if(strcmp(password,"123456")==0)
		{
			printf("µÇÂ¼³É¹¦\n");
			break;
		}
		else
		{
			printf("ÃÜÂëÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë£º\n");
		}
	}
	if(i==3)
	{
		printf("Èý´ÎÃÜÂëÊäÈë´íÎó£¬ÍË³ö³ÌÐò\n");
	}
	return 0;
}
