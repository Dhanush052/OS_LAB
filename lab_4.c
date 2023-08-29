Q.	Write a Program to simulate multi-level queue scheduling algorithm 	considering the following scenario. All the processes in the system are 	divided into two categories – system processes and user processes. Use 	FCFS scheduling for the processes in each queue.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,temp,n;
    float wtavg,tatavg;



    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n],bt[n],su[n],wt[n],tat[n];
    
    

    for (i = 0; i < n; i++)
    {
        pid[i] = i;
        printf("\nEnter the burst time of Process %d :",i+1);
        scanf("%d",&bt[i]);

        printf("For a System Process(0) Else if its a User Process(1):");
        scanf("%d",&su[i]);

    }

   
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];


    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            if(su[i]>su[j])
            {
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp; 

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp; 

                temp = su[i];
                su[i] = su[j];
                su[j] = temp;          
            }



        }




    }

    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }



    printf("\nProcess-ID \t System/User Process \t\t Burst Time \t\t Waiting Time \t\t TAT ");

    for(int i =0;i<n;i++){
        

        printf("\n%d \t\t\t %d \t\t\t %d \t\t\t %d \t\t\t %d",pid[i]+1,su[i],bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time:%0.3f",wtavg/n);
    printf("\nAverage TurnAroundTime:%0.3f",1.0*tatavg/n);


    return 0;
}

