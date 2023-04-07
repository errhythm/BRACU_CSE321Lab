#include<stdio.h>
struct process
{
    int waitingTime;
    int arrivalTime;
    int burstTime;
    int turnaroundTime;
    int completionTime;
    int priority;
};

struct process proc[10];

int main()
{
    int n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time for process %d:\n", i + 1);
        scanf("%d",&proc[i].arrivalTime);
        printf("Enter burst time for process %d:\n", i + 1);
        scanf("%d",&proc[i].burstTime);
        printf("Enter priority for process %d:\n", i + 1);
        scanf("%d",&proc[i].priority);
        temp[i]=proc[i].burstTime;
    }

    proc[9].priority=100000;

    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(proc[short_p].priority > proc[i].priority && proc[i].arrivalTime <= t && proc[i].burstTime > 0)
            {
                short_p=i;
            }
        }

        proc[short_p].burstTime= proc[short_p].burstTime - 1;

        if(proc[short_p].burstTime == 0)
        {
            count++;
            proc[short_p].waitingTime= t + 1 - proc[short_p].arrivalTime - temp[short_p];
            proc[short_p].turnaroundTime= t + 1 - proc[short_p].arrivalTime;
            proc[short_p].completionTime= t + 1;
            total_WT=total_WT+proc[short_p].waitingTime;
            total_TAT=total_TAT+proc[short_p].turnaroundTime;

        }
    }

    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;

    printf("\nProcesses  |  Completion Time  |  Turn Around Time  |  Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("\nP%d\t\t    %d\t\t\t%d\t\t    %d",i+1,proc[i].completionTime,proc[i].turnaroundTime,proc[i].waitingTime);
    }
    printf("\n\n");
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);

    return 0;
}
