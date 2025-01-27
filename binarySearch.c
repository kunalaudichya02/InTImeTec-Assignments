#include<stdio.h>

int binarySearch(int arr[], int key, int low, int high){

    while(low <= high){
        
        int mid = (low+high)/2;

        if(key==arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            return binarySearch(arr, key, mid+1, high);
        }
        else{
            return binarySearch(arr, key, 0, mid-1);
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements an array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    int key;
    scanf("%d", &key);

    int index = binarySearch(arr, key, 0, n-1);
    if (index != -1)
    {
        printf("Element found at index: %d", index);
    }
    else{
        printf("Element not found");
    }

    return 0;
}