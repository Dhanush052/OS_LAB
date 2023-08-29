Q.  Write a C program to simulate deadlock detection.
#include <stdio.h>

int main()
{
    int i, j, np, nr;

    printf("Enter the number of the process and resources: ");
    scanf("%d%d", &np, &nr);
    int alloc[np][nr], request[np][nr], avail[nr], r[nr], w[nr], mark[np];

    printf("Enter the total amount of each resource available: ");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &r[i]);
        avail[j] = r[j];
    }

    printf("Enter the request matrix:\n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &alloc[i][j]);
            avail[j] -= alloc[i][j];
        }
    }

    // marking processes with zero allocation
    for (i = 0; i < np; i++)
    {
        int count = 0;
        for (j = 0; j < nr; j++)
        {
            if (alloc[i][j] == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == nr)
        {
            mark[i] = 1;
        }
    }

    // initialize W with avail
    for (j = 0; j < nr; j++)
    {
        w[j] = avail[j];
    }

    // mark processes with request less than or equal to W
    for (i = 0; i < np; i++)
    {
        int canbeprocessed = 0;
        if (mark[i] != 1)
        {
            for (j = 0; j < nr; j++)
            {
                if (request[i][j] <= w[j])
                    canbeprocessed = 1;
                else
                {
                    canbeprocessed = 0;
                    break;
                }
            }
            if (canbeprocessed)
            {
                mark[i] = 1;

                for (j = 0; j < nr; j++)
                {
                    w[j] += alloc[i][j];
                }
            }
        }
    }

    // checking for unmarked processes
    int deadlock = 0;
    for (i = 0; i < np; i++)
    {
        if (mark[i] != 1)
        {
            deadlock = 1;
        }
    }

    if (deadlock)
    {
        printf("\nDeadlock detected\n");
    }
    else
    {
        printf("\nNo Deadlock detected\n");
    }
}

