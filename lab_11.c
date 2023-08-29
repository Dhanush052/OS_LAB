Q. Write a C program to simulate the following Page Replacement algorithms
	a) FIFO
	b) LRU
	c) Optimal



FIFO

#include <stdio.h>

#define FRAME_SIZE 3 


int findPageInFrames(int frames[], int page, int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int referenceString[] = {2, 3, 4, 2, 1, 3, 7, 5, 4, 3};
    int referenceLength = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames[FRAME_SIZE] = {-1}; 
    int frameIndex = 0; 

    int pageFaults = 0;

    for (int i = 0; i < referenceLength; i++) {
        int currentPage = referenceString[i];

        
        if (!findPageInFrames(frames, currentPage, FRAME_SIZE)) {
            
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % FRAME_SIZE; 
            pageFaults++;
        }

        
        printf("Frames: ");
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
LRU

#include <stdio.h>

int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(void)
{
    int no_of_frames, no_of_pages, counter = 0, flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    int frames[no_of_frames];

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    int pages[no_of_pages];

    int time[no_of_frames];
    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
}
Optimal

#include <stdio.h>

int main(void)
{
    int no_of_frames, no_of_pages, temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    int frames[no_of_frames];

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    int pages[no_of_pages];

    printf("Enter page reference string: ");

    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
}
