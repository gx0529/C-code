#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int time;    //��ʱ��
int N = 0;   //��¼���̸���

typedef struct PCB
{
	//��תʱ��=����ʱ��-����ʱ��
	//��Ȩ��תʱ��=��תʱ��/����ʱ��
	//ƽ����תʱ�� = ��תʱ��/������
	//ƽ����Ȩ��תʱ�� = ��Ȩ��תʱ��/������
	char name[10];//������
	double high;//�߼�
	int ArriveTime;//����ʱ��
	int StartTime;//���̿�ʼʱ��
	int FinishTime;//���̽���ʱ��
	int RunTime;//����ʱ��
	double TurnroundTime;//��תʱ��
	double WeightTurnroundTime;//��Ȩ��תʱ��
	double AverTT;//ƽ����תʱ��
	double AverWTT;//��Ȩƽ����תʱ��	
}PCB;

PCB a[100];
PCB process;

//���̳�ʼ��
void ProcessInit(PCB *p,int N)
{
	int i = 0;
	printf("������̵����ơ�����ʱ�䡢����ʱ��\n");
	for (i=0; i<N; i++)
	{		
		printf("�����%d�����̵ģ�\n������ ����ʱ�� ����ʱ��\n",i+1);
		scanf("%s\t%d\t%d", &p[i].name, &p[i].ArriveTime, &p[i].RunTime);	
	}
}

void Sort(PCB *p[100], int N)
{
	int i = 0;
	for (i=0; i<N; i++)
	{
		int flag = 0;
		int j = 0;
		PCB tmp;
		for(j=0; j<N-i-1; j++)
		{
			if(p[j]->ArriveTime > p[j+1]->ArriveTime)
			{
				tmp = *p[j];
				*p[j] = *p[j+1];
				*p[j+1] = tmp;
				flag = 1;
			}	
		}
		if(flag == 0)
		{
			break;
		}	
	}
}
//�����ȷ�������㷨
void FCFS(PCB *p,int N)
{
	int i = 0;
	printf("�����ȷ�������㷨\n");
	ProcessInit(p,N);
	//����ð������Խ��̽��������ȵ��������ǰ��
	Sort(&p, N);
	time = p[0].ArriveTime;
}

//����ҵ���ȵ����㷨
void SJF(PCB *p, int N)
{
	int num;
	PCB b[100];
	int arrive = 65535;   //Ѱ�����絽��Ľ���
	int min_run = 65535;  //Ѱ����С����ʱ�����
	int i = 0;
	int j = 0;
	int k = 0;
	int state[100];  //����100����־λ
	printf("����ҵ���ȵ����㷨\n");
	ProcessInit(p,N);
	for(i=0; i<N; i++)
	{
		state[i] = 0;
	}
	for(i=0; i<N; i++)
	{
		if(p[i].ArriveTime < arrive)
		{
			arrive = p[i].ArriveTime;
			num = i;
		}
	}
	b[0] = p[num];
	state[num] = 1;
	b[0].FinishTime = b[0].ArriveTime + b[0].RunTime;
	for(k=1; k<N; k++)
	{
		min_run = 65535;
		for(i=0; i<N; i++)
		{
			if(state[i]==1 || p[i].ArriveTime>b[j].FinishTime)  //����������������δ����Ľ�������
			{
				continue;
			}
			else if(p[i].RunTime < min_run)
			{
				min_run = p[i].RunTime;
				num = i;
			}
		}
		state[num] = 1;
		b[++j] = p[num];
		b[j].StartTime = b[j-1].FinishTime;
		b[j].FinishTime = b[j-1].FinishTime + b[j].RunTime;
	}
	for(j=0; j<N; j++)
	{
		p[j] = b[j];
	}
}
	

//�����ȼ������㷨
void PSA(PCB *p, int N)
{
	int num;
	PCB b[100];
	int arrive = 65535;   //Ѱ�����絽��Ľ���
	double max_high = 0;  //Ѱ��������ȼ�����
	int i = 0;
	int j = 0;
	int k = 0;
	int state[100];  //����100����־λ
	printf("�����ȼ������㷨\n");
	printf("������̵����ơ�����ʱ�䡢����ʱ�䡢���ȼ�\n");
	for (i=0; i<N; i++)
	{		
		printf("�����%d�����̵ģ�\n������ ����ʱ�� ����ʱ�� ���ȼ�\n",i+1);
		scanf("%s\t%d\t%d\t%lf", &p[i].name, &p[i].ArriveTime, &p[i].RunTime, &p[i].high);	
	}
	for(i=0; i<N; i++)
	{
		state[i] = 0;
	}
	for(i=0; i<N; i++)
	{
		if(p[i].ArriveTime < arrive)
		{
			arrive = p[i].ArriveTime;
			num = i;
		}
	}
	b[0] = p[num];
	state[num] = 1;
	b[0].FinishTime = b[0].ArriveTime + b[0].RunTime;
	for(k=1; k<N; k++)
	{
		max_high = 0;
		for(i=0; i<N; i++)
		{
			if(state[i]==1 || p[i].ArriveTime>b[j].FinishTime)  //����������������δ����Ľ�������
			{
				continue;
			}
			else if(p[i].high > max_high)
			{
				max_high = p[i].high;
				num = i;
			}
		}
		state[num] = 1;
		b[++j] = p[num];
		b[j].StartTime = b[j-1].FinishTime;
		b[j].FinishTime = b[j-1].FinishTime + b[j].RunTime;
	}
	for(j=0; j<N; j++)
	{
		p[j] = b[j];
	}
}

void SUB(PCB *p, int N)
{
	int i = 0;
	for (i=0; i<N; i++)
	{
		p[i] = p[i+1];
	}
	N--;
}
//����Ӧ�����ȵ����㷨
void HRRN(PCB *p, int N)
{
	int i = 0;
	double time1 = 0;
	double time2 = 0;
	int t0 = 0;
	int t1 = 0;
	PCB tmp;
	int times = 0;//��¼���еķ���ʱ��
	printf("����Ӧ�����ȵ����㷨\n");
	ProcessInit(p,N);
	Sort(&p, N);
	for(i=0; i<N; i++)
	{
		times += p[i].RunTime;
	}
	//����һ����ڶ������и���Ӧ������
	t0 = (p[0].ArriveTime + p[0].RunTime) / p[0].RunTime;
	t1 = (p[1].ArriveTime + p[1].RunTime) / p[1].RunTime;
	if(t0 > t1)
	{
		tmp = p[0];
		p[0] = p[1];
		p[1] = tmp;
	}
	//ִ�е�һ������
	time1 = p[0].ArriveTime;
	printf("\n����Ӧ�ȣ����\n");
	Print(&p[0]);
	time2 = p[0].RunTime;
	//���ݸ���Ӧ�ȸ���������
	for(i=0; i<N; i++)
	{
		int j = 0;
		int k = 0;
		SUB(p, N);
		for (j=0; j<N; j++)
		{
			//��¼ִ����ɽ��̵�ʱ��
			time1 = time1 + time2+ p[j].RunTime;
			//���㵱ǰʣ����̵���Ӧ��
			p[j].high = time1 / p[j].RunTime;
		}
		//������Ӧ�ȸ���������
		for (k=0; k<N; k++)
		{
			int count = 0;
			int j = 0;
			for (j=0; j<N-i-1; j++)
			{
				if (p[j].high < p[j+1].high)
				{
					tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;
					count = 1;
				}
			}
			if (count == 0)
			{
				break;
			}
		}
		time2 = time2 + p[0].RunTime;
		time = p[0].ArriveTime;
		Print(&p[0]);
	}
}

//ʱ��Ƭ��ת�����㷨
void TSR(PCB *p, int N)
{
	float time = 0;    
	int i;    
	int j = 0; 
	int num = 0;
	PCB b[100];
	printf("ʱ��Ƭ��ת�㷨\n");
	ProcessInit(p,N);
	printf("ʱ��Ƭ��СΪ��");
	scanf("%d", &num);  
	for(i=0; i<N; i++)    
	{       
		//�Խ��̵ĳ�ʼ����Ϣ����
		b[j++] = p[i];
	}     
	time = p[0].ArriveTime;
	while(charge())    
	{        
		for (i=0; i<N; i++)
		{            
			if (p[i].ArriveTime>time)
			{                
				time = p[i].ArriveTime;
			}            
			if (p[i].run_flag == 0)//�ý��̻�δ����            
			{                
				if (p[i].start_flag == 0)//������������˵�����ý����ǵ�һ��ִ�У���¼��ʼִ��ʱ��                
				{                    
					p[i].StartTime = time_temp;
					p[i].start_flag = 1;
				}                
				if (p[i].RunTime / time_counter>1)//������������ʱ��Ƭδִ��                
				{                    
					p[i].RunTime = p[i].run_time - time_counter;
					time_temp=time_temp+time_counter;                
				}                
				else if (p[i].RunTime - time_counter == 0)
				{                    
					time_temp=time_temp+time_counter;                    
					p[i].FinishTime = time_temp;
					p[i].run_flag = 1;
					p[i].RunTime = b[i].runTime;
				}                
				else               
				{                    
					time_temp = time_temp + p[i].RunTime;
					p.[i].FinishTime = time_temp;
					p.[i].run_flag = 1;
					p.[i].RunTime = b[i].RunTime;
				}            
			}        
		}    
	}
}

//�ṹ���ʼ��
void pcbInit()
{
	process.StartTime = 0;
	process.FinishTime = 0;
	process.TurnroundTime = 0;
	process.WeightTurnroundTime = 0;
}

void Print(PCB *p)
{	
	int i = 0;
	p->StartTime = time;
	printf("\nʱ��: %d,��ǰ��ʼ������ҵ��%s\n\n", time, p->name);
	time = time + p->RunTime;
	p->FinishTime = time;
	p->TurnroundTime = p->FinishTime - p->StartTime;
	p->WeightTurnroundTime = p->TurnroundTime / p->RunTime;
	p->AverTT = p->TurnroundTime / N;
	p->AverWTT = p->WeightTurnroundTime / N;
	printf("����ʱ�� ��ʼʱ�� ����ʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ�� ƽ����תʱ�� ƽ����Ȩ��תʱ��\n");
	printf("%4d  %7d  %7d  %7d  %8.1lf  %9.2lf	%9.2lf %11.2lf\n", p->ArriveTime, 
		p->StartTime, p->RunTime, p->FinishTime, p->TurnroundTime, p->WeightTurnroundTime,p->AverTT, p->AverWTT);
}

void Loop(PCB *p)
{
	int i = 0;
	for (i=0; i<N; i++)
	{
		Print(&p[i]);
	}
}

int Game()
{
	int n = 0;
	printf("========================\n");
	printf("1.�����ȷ����㷨\n");
	printf("2.����ҵ�����㷨\n");
	printf("3.�����ȼ������㷨\n");
	printf("4.����Ӧ�����ȵ����㷨\n");
	printf("5.ʱ��Ƭ��ת�����㷨\n");
	printf("0.�˳�\n");
	printf("========================\n");
	printf("��ѡ����̵����㷨��");
	scanf("%d", &n);
	return n;
}
int main()
{
	int n = 0;
	printf("���̸�����");
	scanf("%d",&N);
	while (1)
	{
		pcbInit();
		n = Game();
		switch (n)
		{
		case 1:
			FCFS(a,N);
			Loop(a);
			break;
		case 2:
			SJF(a,N);
			Loop(a);
			break;
		case 3:
			PSA(a,N);
			Loop(a);
			break;
		case 4:
			HRRN(a,N);
			break;
		case 5:
			TSR(a,N);
			Loop(a);
			break;
		case 0:
			printf("welcome bye\n");
			break;
		default:
			printf("�����������ȷ���룡");
		}
	}
	return 0;
}

