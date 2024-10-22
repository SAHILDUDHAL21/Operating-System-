#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sort(int *array, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;

    int n = argc - 2;
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) array[i] = atoi(argv[i + 2]);

    sort(array, n);
    
    char *args[n + 2];
    args[0] = "./execve1";
    args[1] = argv[1];
    for (int i = 0; i < n; i++) {
        args[i + 2] = malloc(12);
        sprintf(args[i + 2], "%d", array[i]);
    }
    args[n + 2] = NULL;

    if (fork() == 0) {
        execve(args[0], args, NULL);
        perror("execve failed");
        exit(1);
    }

    for (int i = 2; i < n + 2; i++) free(args[i]);
    free(array);
    return 0;
}
