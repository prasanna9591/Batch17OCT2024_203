#include <stdio.h>

void findSubArray(int arr[], int n, int sum) {
    int current_sum, i, j;

    // Iterate through the array
    for (i = 0; i < n; i++) {
        current_sum = arr[i];

        // Try different ending points for the sub-array
        for (j = i + 1; j <= n; j++) {
            if (current_sum == sum) {
                printf("Sum found between indexes %d and %d\n", i, j - 1);
                return;
            }
            if (current_sum > sum || j == n)
                break;
            current_sum = current_sum + arr[j];
        }
    }

    printf("No subarray found\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum;
    printf("Enter the sum: ");
    scanf("%d", &sum);

    findSubArray(arr, n, sum);

    return 0;
}

