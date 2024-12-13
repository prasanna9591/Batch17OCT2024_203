#include <stdio.h>
#include <stdlib.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the maximum GCD after removing one element
int findMaxGCD(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    // Create prefix and suffix GCD arrays
    int prefixGCD[n];
    int suffixGCD[n];

    prefixGCD[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);
    }

    suffixGCD[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixGCD[i] = gcd(suffixGCD[i + 1], arr[i]);
    }

    // Calculate the maximum GCD after removing one element
    int maxGCD = suffixGCD[1]; // Removing the first element
    if (n > 1) {
        maxGCD = suffixGCD[1]; // Removing the first element
        maxGCD = (maxGCD > prefixGCD[n - 2]) ? maxGCD : prefixGCD[n - 2]; // Removing the last element
    }

    for (int i = 1; i < n - 1; i++) {
        int currentGCD = gcd(prefixGCD[i - 1], suffixGCD[i + 1]);
        if (currentGCD > maxGCD) {
            maxGCD = currentGCD;
        }
    }

    return maxGCD;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = findMaxGCD(arr, n);
    printf("The maximum GCD after removing one element is: %d\n", result);

    return 0;
}

