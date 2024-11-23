#include <stdio.h>
#include "functions.h"

int main() 
{
    int n = readInt("Enter the size of the array: ");

    int arr[n];
    readArray(arr, n);

    int sum = readInt("Enter the sum: ");

    findSubArray(arr, n, sum);

    return 0;
}

