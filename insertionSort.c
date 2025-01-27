#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && a[j-1]>a[j]){
            swap(&a[j], &a[j-1]);
            j--;
        }
    }
}

int main(){
    printf("Enter size of an array.\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements an array.\n");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Unsorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    
    insertionSort(arr, n);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}