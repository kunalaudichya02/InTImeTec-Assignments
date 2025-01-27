#include <stdio.h>

void twoPointerSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int sum = arr[low] + arr[high];

        if (sum == target) {
            printf("Pair found: (%d, %d)\n", arr[low], arr[high]);
            return;
        } else if (sum < target) {
            low++; 
        } else {
            high--; 
        }
    }

    printf("No pair found\n");
}

int main() {
   printf("Enter size of an array.\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements an array.\n");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter target sum: ");
    int target;
    scanf("%d", &target);

    twoPointerSearch(arr, n, target);

    return 0;
}
