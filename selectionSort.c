#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min]) {
                min = j;
            }
            
        }
        swap(&a[i], &a[min]);
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
    
    
    selectionSort(arr, n);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}