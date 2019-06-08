#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    // 从第二个开始
    {
        int temp = arr[i];
        printf("get %d\n", arr[i]);
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        // 与arr[i]前面的比较
        {
            // arr[i-1] 后移
            printf("%d 后移:     ", arr[j-1]);
            arr[j] = arr[j - 1];
            display(arr, size);
        }
        // 插入到空位
        arr[j] = temp;
        printf("The %d sort: ", i);
        display(arr, size);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);

    insertion_sort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}