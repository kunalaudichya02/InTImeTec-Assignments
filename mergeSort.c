#include<stdio.h>

void merge(int a[], int low, int mid, int high){
    int size = high-low+1;
    int temp[size];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left <= mid && right <= high){
        if(a[left]<=a[right]){
            temp[i++] = a[left];
            left++;
        }
        else{
            temp[i++] = a[right];
            right++;
        }
    }

    while(left<= mid){
        temp[i++] = a[left];
        left++;
    }
    while(right <= high){
        temp[i++] = a[right];
        right++;

    }

    for(int j=0; j<size; j++){
        a[low+j] = temp[j];
    }
}
void mergeSort(int a[], int low, int high){
    if(low==high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
    
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
    
    
    mergeSort(arr,0, n-1);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}