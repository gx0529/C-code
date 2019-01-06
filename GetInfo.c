#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int time;    //计时器
int N = 0;   //记录进程个数

typedef struct PCB
{
	//周转时间=结束时间-到达时间
	//带权周转时间=周转时间/服务时间
	//平均周转时间 = 周转时间/进程数
	//平均带权周转时间 = 带权周转时间/进程数
	char name[10];//进程名
	double high;//高级
	int ArriveTime;//到达时间
	int StartTime;//进程开始时间
	int FinishTime;//进程结束时间
	int RunTime;//运行时间
	double TurnroundTime;//周转时间
	double WeightTurnroundTime;//带权周转时间
	double AverTT;//平均周转时间
	double AverWTT;//带权平均周转时间	
}PCB;

PCB a[100];
PCB process;

//进程初始化
void ProcessInit(PCB *p,int N)
{
	int i = 0;
	printf("输入进程的名称、到达时间、运行时间\n");
	for (i=0; i<N; i++)
	{		
		printf("输入第%d个进程的：\n进程名 到达时间 运行时间\n",i+1);
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
//先来先服务调度算法
void FCFS(PCB *p,int N)
{
	int i = 0;
	printf("先来先服务调度算法\n");
	ProcessInit(p,N);
	//采用冒泡排序对进程进行排序，先到达就排在前面
	Sort(&p, N);
	time = p[0].ArriveTime;
}

//短作业优先调度算法
void SJF(PCB *p, int N)
{
	int num;
	PCB b[100];
	int arrive = 65535;   //寻找最早到达的进程
	int min_run = 65535;  //寻找最小运行时间进程
	int i = 0;
	int j = 0;
	int k = 0;
	int state[100];  //设置100个标志位
	printf("短作业优先调度算法\n");
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
			if(state[i]==1 || p[i].ArriveTime>b[j].FinishTime)  //如果遇到已排序或者未到达的进程跳过
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
	

//高优先级调度算法
void PSA(PCB *p, int N)
{
	int num;
	PCB b[100];
	int arrive = 65535;   //寻找最早到达的进程
	double max_high = 0;  //寻找最高优先级进程
	int i = 0;
	int j = 0;
	int k = 0;
	int state[100];  //设置100个标志位
	printf("高优先级调度算法\n");
	printf("输入进程的名称、到达时间、运行时间、优先级\n");
	for (i=0; i<N; i++)
	{		
		printf("输入第%d个进程的：\n进程名 到达时间 运行时间 优先级\n",i+1);
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
			if(state[i]==1 || p[i].ArriveTime>b[j].FinishTime)  //如果遇到已排序或者未到达的进程跳过
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
//高响应比优先调度算法
void HRRN(PCB *p, int N)
{
	int i = 0;
	double time1 = 0;
	double time2 = 0;
	int t0 = 0;
	int t1 = 0;
	PCB tmp;
	int times = 0;//记录所有的服务时间
	printf("高响应比优先调度算法\n");
	ProcessInit(p,N);
	Sort(&p, N);
	for(i=0; i<N; i++)
	{
		times += p[i].RunTime;
	}
	//将第一个与第二个进行高响应比排序
	t0 = (p[0].ArriveTime + p[0].RunTime) / p[0].RunTime;
	t1 = (p[1].ArriveTime + p[1].RunTime) / p[1].RunTime;
	if(t0 > t1)
	{
		tmp = p[0];
		p[0] = p[1];
		p[1] = tmp;
	}
	//执行第一个程序
	time1 = p[0].ArriveTime;
	printf("\n高响应比：最大\n");
	Print(&p[0]);
	time2 = p[0].RunTime;
	//根据高响应比给进程排序
	for(i=0; i<N; i++)
	{
		int j = 0;
		int k = 0;
		SUB(p, N);
		for (j=0; j<N; j++)
		{
			//记录执行完成进程的时间
			time1 = time1 + time2+ p[j].RunTime;
			//计算当前剩余进程的响应比
			p[j].high = time1 / p[j].RunTime;
		}
		//根据响应比给进程排序
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

//时间片轮转调度算法
void TSR(PCB *p, int N)
{
	float time = 0;    
	int i;    
	int j = 0; 
	int num = 0;
	PCB b[100];
	printf("时间片轮转算法\n");
	ProcessInit(p,N);
	printf("时间片大小为：");
	scanf("%d", &num);  
	for(i=0; i<N; i++)    
	{       
		//对进程的初始化信息备份
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
			if (p[i].run_flag == 0)//该进程还未结束            
			{                
				if (p[i].start_flag == 0)//该条件成立则说明，该进程是第一次执行，记录开始执行时间                
				{                    
					p[i].StartTime = time_temp;
					p[i].start_flag = 1;
				}                
				if (p[i].RunTime / time_counter>1)//至少有两倍的时间片未执行                
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

//结构体初始化
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
	printf("\n时刻: %d,当前开始运行作业：%s\n\n", time, p->name);
	time = time + p->RunTime;
	p->FinishTime = time;
	p->TurnroundTime = p->FinishTime - p->StartTime;
	p->WeightTurnroundTime = p->TurnroundTime / p->RunTime;
	p->AverTT = p->TurnroundTime / N;
	p->AverWTT = p->WeightTurnroundTime / N;
	printf("到达时间 开始时间 服务时间 完成时间 周转时间 带权周转时间 平均周转时间 平均带权周转时间\n");
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
	printf("1.先来先服务算法\n");
	printf("2.短作业优先算法\n");
	printf("3.高优先级调度算法\n");
	printf("4.高响应比优先调度算法\n");
	printf("5.时间片轮转调度算法\n");
	printf("0.退出\n");
	printf("========================\n");
	printf("请选择进程调度算法：");
	scanf("%d", &n);
	return n;
}
int main()
{
	int n = 0;
	printf("进程个数：");
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
			printf("输入错误，请正确输入！");
		}
	}
	return 0;
}

