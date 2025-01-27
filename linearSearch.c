#include <stdio.h>


int linearSearch(int arr[], int n, int key ){
    for(int i=0; i<n; i++ ){
        if(arr[i] == key){
            return i;
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

    int index = linearSearch(arr, n, key);
    if (index != -1)
    {
        printf("Element found at index: %d", index);
    }
    else{
        printf("Element not found");
    }

    return 0;
}