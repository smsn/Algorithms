#include <stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shell_sort(int arr[], int size) {
    for (int D = size / 2; D > 0; D /= 2) {
        // 每隔D位进行一次插入排序
        printf("\n增量: %d\n", D);
        for (int i = D; i < size; i++) {
            // 从arr[D]开始
            int temp = arr[i];
            printf("arr[%d]:%d compare arr[%d]:%d\n", i, arr[i], i - D, arr[i - D]);
            int j;
            for (j = i; j >= D && arr[j - D] > temp; j -= D) {
                // 与arr[i-D]比较
                // arr[i-D] 后移
                arr[j] = arr[j - D];
                printf("%d 后移:     ", arr[j - D]);
                display(arr, size);
            }
            // 插入到空位
            arr[j] = temp;
            printf("The %d sort: ", i - D + 1);
            display(arr, size);
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

    shell_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}