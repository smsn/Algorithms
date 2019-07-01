#include <stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int tmp[], int left_start, int right_start, int right_end) {
    // 合并相邻有序子列
    int tmp_start = left_start;
    int left_end = right_start - 1;
    int size = right_end - left_start + 1;

    while (left_start <= left_end && right_start <= right_end) {
        if (arr[left_start] <= arr[right_start]) {
            tmp[tmp_start++] = arr[left_start++];
        } else {
            tmp[tmp_start++] = arr[right_start++];
        }
    }
    // 导入剩余元素
    while (left_start <= left_end) {
        tmp[tmp_start++] = arr[left_start++];
    }

    while (right_start <= right_end) {
        tmp[tmp_start++] = arr[right_start++];
    }

    // display(tmp, 9);
    // 导回到原始数组
    for (int i = 0; i < size; i++) {
        arr[right_end] = tmp[right_end];
        right_end--;
    }
}

void m_sort(int arr[], int tmp[], int left_start, int right_end) {
    // 递归
    int center;
    if (left_start < right_end) {
        center = (left_start + right_end) / 2;
        m_sort(arr, tmp, left_start, center);
        m_sort(arr, tmp, center + 1, right_end);
        merge(arr, tmp, left_start, center + 1, right_end);
    }
}

void merge_sort(int arr[], int size) {
    int tmp[size];
    for (int i = 0; i < size; i++) {
        tmp[i]=0;
    }
    m_sort(arr, tmp, 0, size - 1);
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

    merge_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}