Q.	Write a C program to simulate the following non-preemptive CPU 	scheduling algorithm to find turnaround time and waiting time.
		- Priority
		- Round Robin

Priority

#include<stdio.h>  
#include<stdlib.h>  
  
struct process {  
    int proc_id;  
    int bt;  
    int priority;  
    int wt;  
    int tat;  
};  
  
void find_wt(struct process[], int, int[]);  
void find_tat(struct process[], int, int[], int[]);  
  
void find_average_time(struct process[], int);  
  
void priority_scheduling(struct process[], int);  
  
int main()  
{  
    int n, i;  
    struct process proc[10];  
  
printf("Enter the number of processes: ");  
scanf("%d", &n);  
  
for(i = 0; i< n; i++)  
    {  
printf("\nEnter the process ID: ");  
scanf("%d", &proc[i].proc_id);  
  
printf("Enter the burst time: ");  
scanf("%d", &proc[i].bt);  
  
printf("Enter the priority: ");  
scanf("%d", &proc[i].priority);  
    }  
  
priority_scheduling(proc, n);  
    return 0;  
}  
  
void find_wt(struct process proc[], int n, int wt[])  
{  
    int i;  
    wt[0] = 0;  
  
for(i = 1; i< n; i++)  
    {  
    wt[i] = proc[i - 1].bt + wt[i - 1];  
    }  
}  
  
void find_tat(struct process proc[], int n, int wt[], int tat[])  
{  
    int i;  
for(i = 0; i< n; i++)  
    {  
tat[i] = proc[i].bt + wt[i];  
    }  
}  
  
void find_average_time(struct process proc[], int n)  
{  
    int wt[10], tat[10], total_wt = 0, total_tat = 0, i;  
  
find_wt(proc, n, wt);  
find_tat(proc, n, wt, tat);  
  
printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");  
  
for(i = 0; i< n; i++)  
    {  
total_wt = total_wt + wt[i];  
total_tat = total_tat + tat[i];  
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].proc_id, proc[i].bt, proc[i].priority, wt[i], tat[i]);  
    }  
  
printf("\n\nAverage Waiting Time = %f", (float)total_wt/n);  
printf("\nAverage Turnaround Time = %f\n", (float)total_tat/n);  
}  
  
void priority_scheduling(struct process proc[], int n)  
{  
int i, j, pos;  
struct process temp;  
for(i = 0; i< n; i++)  
{  
    pos = i;  
for(j = i + 1; j < n; j++)  
    {  
        if(proc[j].priority< proc[pos].priority)  
            pos = j;  
    }  
  
    temp = proc[i];  
    proc[i] = proc[pos];  
    proc[pos] = temp;  
}  
  
find_average_time(proc, n);  
}  
Round Robin

#include<stdio.h>  
#include<stdlib.h>  
  
struct process {  
    int proc_id;  
    int bt;  
    int priority;  
    int wt;  
    int tat;  
};  
  
void find_wt(struct process[], int, int[]);  
void find_tat(struct process[], int, int[], int[]);  
  
void find_average_time(struct process[], int);  
  
void priority_scheduling(struct process[], int);  
  
int main()  
{  
    int n, i;  
    struct process proc[10];  
  
printf("Enter the number of processes: ");  
scanf("%d", &n);  
  
for(i = 0; i< n; i++)  
    {  
printf("\nEnter the process ID: ");  
scanf("%d", &proc[i].proc_id);  
  
printf("Enter the burst time: ");  
scanf("%d", &proc[i].bt);  
  
printf("Enter the priority: ");  
scanf("%d", &proc[i].priority);  
    }  
  
priority_scheduling(proc, n);  
    return 0;  
}  
  
void find_wt(struct process proc[], int n, int wt[])  
{  
    int i;  
    wt[0] = 0;  
  
for(i = 1; i< n; i++)  
    {  
    wt[i] = proc[i - 1].bt + wt[i - 1];  
    }  
}  
  
void find_tat(struct process proc[], int n, int wt[], int tat[])  
{  
    int i;  
for(i = 0; i< n; i++)  
    {  
tat[i] = proc[i].bt + wt[i];  
    }  
}  
  
void find_average_time(struct process proc[], int n)  
{  
    int wt[10], tat[10], total_wt = 0, total_tat = 0, i;  
  
find_wt(proc, n, wt);  
find_tat(proc, n, wt, tat);  
  
printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");  
  
for(i = 0; i< n; i++)  
    {  
total_wt = total_wt + wt[i];  
total_tat = total_tat + tat[i];  
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].proc_id, proc[i].bt, proc[i].priority, wt[i], tat[i]);  
    }  
  
printf("\n\nAverage Waiting Time = %f", (float)total_wt/n);  
printf("\nAverage Turnaround Time = %f\n", (float)total_tat/n);  
}  
  
void priority_scheduling(struct process proc[], int n)  
{  
int i, j, pos;  
struct process temp;  
for(i = 0; i< n; i++)  
{  
    pos = i;  
for(j = i + 1; j < n; j++)  
    {  
        if(proc[j].priority< proc[pos].priority)  
            pos = j;  
    }  
  
    temp = proc[i];  
    proc[i] = proc[pos];  
    proc[pos] = temp;  
}  
  
find_average_time(proc, n);  
}  
