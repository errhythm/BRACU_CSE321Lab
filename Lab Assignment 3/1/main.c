// Online C compiler to run C program online
#include <stdio.h>


struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
};

void waitingTime(struct Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].burstTime;

    int complete = 0, t = 0, minm = 10000000;
    int shortest = 0, finish_time;
    int check = 0;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (proc[j].arrivalTime <= t && rt[j] < minm && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }
        if (check == 0) {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = 10000000;
        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
        }
        wt[shortest] = finish_time - proc[shortest].burstTime - proc[shortest].arrivalTime;
        if (wt[shortest] < 0)
            wt[shortest] = 0;
        t++;
    }
}

void turnAroundTime(struct Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].burstTime + wt[i];
}

void completionTime(struct Process proc[], int n, int tat[], int ct[])
{
    for (int i = 0; i < n; i++)
        ct[i] = proc[i].arrivalTime + tat[i];
}

void averageTime(struct Process proc[], int n)
{
    int wt[n], tat[n], ct[n];
    double total_wt, total_tat, avg_wt, avg_tat;

    waitingTime(proc, n, wt);

    turnAroundTime(proc, n, wt, tat);

    completionTime(proc, n, tat, ct);


    printf("\nProcesses  |  Completion Time  |  Turn Around Time  |  Waiting Time\n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n %d                 %d                    %d                  %d ", proc[i].pid, ct[i], tat[i], wt[i]);
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    printf("\n\nAverage waiting time = %.2f ", avg_wt);
    printf("\nAverage turn around time = %.2f ", avg_tat);
}

int main()
{
    int n;
    printf("Enter number of processes:\n");
    scanf(" %d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d:\n", i + 1);
        scanf(" %d", &proc[i].arrivalTime);
        printf("Enter burst time process %d:\n", i + 1);
        scanf(" %d", &proc[i].burstTime);
        proc[i].pid = i + 1;
    }

    averageTime(proc, n);

    return 0;
}