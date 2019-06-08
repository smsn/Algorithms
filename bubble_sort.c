#include <stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size) {
    for (int i = size; i > 1; i--) {
        // 只剩一个时停止
        int stop = 1;
        for (int j = 0; j < i - 1; j++) {
            // arr[i]及以后已经有序
            if (arr[j] > arr[j + 1]) {
                printf("swap %d %d.\n", arr[j], arr[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                stop = 0;
            }
        }
        printf("The %d sort: ", size - i + 1);
        display(arr, size);
        if (1 == stop) {
            // 无交换则已有序
            printf("No swap.\n");
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    int i;
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    bubble_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}