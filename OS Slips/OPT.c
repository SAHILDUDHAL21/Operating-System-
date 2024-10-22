#include <stdio.h>
int findOptimal(int pages[], int temp[], int n, int current, int frames) {
    int pos = -1, farthest = current;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = current; j < n; j++) {
            if (temp[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) // If a page is not going to be used again
            return i;
    }
    return (pos == -1) ? 0 : pos; // If all pages will be used, replace the farthest one
}
int main() {
    int i, j, n, frames, pages[30], temp[10], flag1, flag2, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize frames to -1 (indicating empty)
    for (i = 0; i < frames; i++) {
        temp[i] = -1;
    }
    printf("\nPage Reference String  |  Frames\n");

    for (i = 0; i < n; i++) {
        flag1 = flag2 = 0;
        // Check if the page is already in one of the frames
        for (j = 0; j < frames; j++) {
            if (temp[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }
        // If the page is not in the frame, find where to place it
        if (flag1 == 0) {
            // Find an empty frame to place the page
            for (j = 0; j < frames; j++) {
                if (temp[j] == -1) {
                    temp[j] = pages[i];
                    flag2 = 1;
                    faults++;
                    break;
                }
            }
        }
        // If no empty frame, use the optimal page replacement strategy
        if (flag2 == 0) {
            int pos = findOptimal(pages, temp, n, i + 1, frames);
            temp[pos] = pages[i];
            faults++;
        }
        // Display the current status of frames
        printf("\n%2d\t\t\t", pages[i]);
        for (j = 0; j < frames; j++) {
            if (temp[j] != -1)
                printf("%2d ", temp[j]);
            else
                printf("- ");
        }
    }
    printf("\n\nTotal Page Faults: %d\n", faults);
    return 0;
}
