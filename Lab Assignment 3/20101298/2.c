#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
};


void findWaitingTime(int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n], t = 0;
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}


void findavgTime(struct Process proc[], int n, int quantum)
{
    int wt[n], tat[n], ct[n], bt[n];
    for (int i = 0; i < n; i++)
    {
        bt[i] = proc[i].burstTime;
    };
    findWaitingTime(n, bt, wt, quantum);
    findTurnAroundTime(n, bt, wt, tat);

    printf("\nProcesses    Completion Time    Turnaround Time    Waiting Time\n");
    for (int i = 0; i < n; i++)
        printf("\n P%d            %d                %d                 %d", proc[i].pid, tat[i], tat[i], wt[i]);

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    printf("\n\nAverage waiting time = %.2f", total_wt / n);
    printf("\nAverage turn around time = %.2f", total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    int quantum;
    printf("Enter the time quantum in ms: \n");
    scanf("%d", &quantum);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: \n", i + 1);
        scanf("%d", &proc[i].burstTime);
        proc[i].pid = i + 1;
    }

    findavgTime(proc, n, quantum);
    return 0;
}
