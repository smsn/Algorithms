#include <stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_min(int arr[], int start, int end) {
    int min_id = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[min_id]) {
            min_id = i;
        }
    }
    return min_id;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min_id = find_min(arr, i, size - 1);
        if (i != min_id) {
            printf("min is %d. swap with %d.\n", arr[min_id], arr[i]);
            swap(&arr[i], &arr[min_id]);
        }
        printf("The %d sort: ", i + 1);
        display(arr, size);
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

    selection_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}