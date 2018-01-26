//Implementation of FCFS (First Come First Serve)
#include<stdio.h>
#include<conio.h>
void main()
{
int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
clrscr();
printf("Enter the total number of process");
scanf("%d",&n);
printf("Enter the process burst time");
for(i=0;i<n;i++)
{
printf("p[%d]:",(i+1));
scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
	wt[i]=wt[i]+bt[j];
}
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
	tat[i]=bt[i]+wt[i];
	avwt+=wt[i];
	avtat+=tat[i];
	printf("\np[%d]\t\t%d\t\t%d\t\t %d\t\t",i+1,bt[i],wt[i],tat[i]);

}
avwt/=i;
avtat/=i;
printf("\n Average waiting Time:%d",avwt);
printf("\n Average Turnaround Time:%d",avtat);
getch();
}
//*****************output*******************
/* Enter the total number of process 5
Enter the process burst timep[1]:10
p[2]:20
p[3]:30
p[4]:40
p[5]:50

Process         Burst Time      Waiting Time    Turnaround Time
p[1]            10              0                10
p[2]            20              10               30
p[3]            30              30               60
p[4]            40              60               100
p[5]            50              100              150
 Average waiting Time:40
 Average Turnaround Time:70










*/










