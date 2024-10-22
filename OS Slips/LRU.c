#include <stdio.h>

int findLRU(int time[], int frames) 
{
    int min = time[0], pos = 0;
    for (int i = 1; i < frames; i++)
    {
        if (time[i] < min) 
        { 
            min = time[i]; 
            pos = i; 
        }
    }
    return pos;
}

int main() 
{
    int n, frames, pages[30], temp[10] = {-1}, time[10] = {0}, faults = 0, hits = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("\nPage Reference | Frames\n");
    for (int i = 0; i < n; i++) 
    {
        int flag = 0;
        for (int j = 0; j < frames; j++) 
        {
            if (temp[j] == pages[i]) 
            {
                time[j] = ++counter; 
                hits++; 
                flag = 1; 
                break; 
            }
            if (temp[j] == -1) 
            {
                temp[j] = pages[i];
                time[j] = ++counter; 
                faults++; 
                flag = 1; 
                break; 
            }
        }
        if (!flag) 
        {
            temp[findLRU(time, frames)] = pages[i];
            time[findLRU(time, frames)] = ++counter; 
            faults++;
        }
        printf("%2d            | ", pages[i]);
        for (int j = 0; j < frames; j++)
        {
            printf("%2s ", temp[j] != -1 ? (temp[j] < 10 ? " " : "") : "-");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
    return 0;
}
