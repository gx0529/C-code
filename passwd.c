#include <stdio.h>

int main()
{
	char password[10]={0};
	int i=0;
	int j=0;
	for(i=0; i<3; i++)
	{
		printf("���������룺");
		scanf("%s",password);
		if(strcmp(password,"123456")==0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("��������������������룺\n");
		}
	}
	if(i==3)
	{
		printf("����������������˳�����\n");
	}
	return 0;
}
