//Implementation of priority scheduling Algorithm
#include<stdio.h>
#include<conio.h>
void main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    clrscr();
    printf("Enter Total Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
	printf("\nP[%d]\n",i+1);
	printf("Burst Time:");
	scanf("%d",&bt[i]);
	printf("Priority:");
	scanf("%d",&pr[i]);
	p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
	pos=i;
	for(j=i+1;j<n;j++)
	{
	    if(pr[j]<pr[pos])
		pos=j;
	}

	temp=pr[i];
	pr[i]=pr[pos];
	pr[pos]=temp;

	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
    }

    wt[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
	wt[i]=0;
	for(j=0;j<i;j++)
	    wt[i]+=bt[j];

	total+=wt[i];
    }

    avg_wt=total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
	tat[i]=bt[i]+wt[i];     //calculate turnaround time
	total+=tat[i];
	printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

    getch();
}
//*****************************output***************************
Enter the number of  Process:4

P[1]
Burst Time:10                                                                   
Priority:10                                                                     
                                                                                
P[2]                                                                            
Burst Time:2                                                                    
Priority:7                                                                      
                                                                                
P[3]                                                                            
Burst Time:3
Priority:9                                                                      
                                                                                
P[4]                                                                            
Burst Time:1                                                                    
Priority:12                                                                     
                                                                                
Process     Burst Time          Waiting Time    Turnaround Time                 
P[2]              2                 0                   2                       
P[3]              3                 2                   5                       
P[1]              10                5                   15                      
P[4]              1                 15                  16                      
                                                                                
Average Waiting Time=5                                                          
Average Turnaround Time=9                                                       
                                                                                


















                                                                                
