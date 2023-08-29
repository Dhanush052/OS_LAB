Q. 	Write a C program to simulate the following non-preemptive CPU    	scheduling algorithm to find Turnaround time and waiting time.
		- FCFS 
		- SJF (preemptive & Non- preemptive)

FCFS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float waitingTime, turnAroundTime;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    float *bt = (float *)malloc(n * sizeof(float));
    float *wt = (float *)malloc(n * sizeof(float));
    float *tt = (float *)malloc(n * sizeof(float));
    printf("Enter the burst times of %d processes: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &bt[i]);
    }
    printf("\nThe details of the processes are as below:\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            wt[0] = 0;
        }
        else
        {
            wt[i] = bt[i - 1] + wt[i - 1];
        }
        tt[i] = bt[i] + wt[i];
        printf("%d\t%f\t%f\t%f\n", i + 1, bt[i], tt[i], wt[i]);
        waitingTime += wt[i];
        turnAroundTime += tt[i];
    }
    printf("The average waiting time is: %f", waitingTime/(float)n);
    printf("\nThe average turn around time is: %f", turnAroundTime / n);
    return 0;
}
SJF (Non-Preemptive)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,index;
    float WT,TurnAroundTime,temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    float *bt = (float *)malloc(n * sizeof(float));
    float *wt = (float *)malloc(n * sizeof(float));
    float *tt = (float *)malloc(n * sizeof(float));
    printf("Enter the burst times of %d processes: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &bt[i]);
    }

    for(i = 0; i < n-1; i++){
        // index = i;
        for(j=0; j < n-i-1; j++){

            if(bt[j]>bt[j+1]){
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }



        }
    }



 printf("\nThe details of the processes are as below:\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            wt[0] = 0;
        }
        else
        {
            wt[i] = bt[i - 1] + wt[i - 1];
        }
        tt[i] = bt[i] + wt[i];
        printf("%d\t%f\t%f\t\t%f\n", i + 1, bt[i], tt[i], wt[i]);
        WT = WT + wt[i];
        TurnAroundTime = TurnAroundTime + tt[i];
    }
    printf("The average waiting time is: %f", WT/(float)n);
    printf("\nThe average turn around time is: %f", TurnAroundTime/n);
    return 0;
}

SJF (Pre-Emptive)

#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int pid;
    int bt;
    int art;
};

void findWaitingTime(struct Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
    {
        rt[i] = proc[i].bt;
    }

    int complete = 0, t = 0, minm = 99999;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n)
    {

        for (int j = 0; j < n; j++)
        {
            if ((proc[j].art <= t) &&
                (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];

        if (minm == 0)
            minm = 99999;

        if (rt[shortest] == 0)
        {

            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findavgTime(struct Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }

    printf("Average waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];

    printf("Enter the burst times and arrival times of %d processes: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &proc[i].bt, &proc[i].art);
        proc[i].pid = i + 1;
    }

    findavgTime(proc, n);
    return 0;
}

