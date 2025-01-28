#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        int ifSwapped = 0;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                ifSwapped=1;
            }
        }
        if(ifSwapped==0){
            break;
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
    
    
    bubbleSort(arr, n);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}