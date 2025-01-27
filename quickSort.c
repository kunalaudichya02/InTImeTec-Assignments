#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{

    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (a[i] <= pivot && i < high)
        {
            i++;
        }
        while (a[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}
void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(a, low, high);

        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

int main()
{
    printf("Enter size of an array.\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements an array.\n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}