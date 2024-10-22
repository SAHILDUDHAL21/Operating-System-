#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int n, int item) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == item) return mid;
        if (array[mid] < item) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;

    int item = atoi(argv[1]);
    int n = argc - 2;
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) array[i] = atoi(argv[i + 2]);

    int result = binary_search(array, n, item);
    printf("Item %d %s\n", item, result != -1 ? "found" : "not found");

    free(array);
    return 0;
}
