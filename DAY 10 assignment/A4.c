/*
	DESC :Rotate array every kth element
	
	NAME :Prasanna
	
	Date :7th,Nov 2024

*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int arr[], int start, int end);

void rotate(int arr[], int size, int key);

int main() 
{
    int size, key;
    int iter;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
   
    printf("Enter the elements of the array:\n");
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &key);

    rotate(arr, size, key);

    printf("Rotated array: ");
    for (iter = 0; iter < size; iter++) 
    {
        printf("%d ", arr[iter]);
    }
    printf("\n");


    return 0;
}
void reverse(int arr[], int start, int end) 
{
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int arr[], int size, int key) 
{
    int iter;
    for ( iter = 0; iter < size; iter += key) 
    {
        int end = (iter + key - 1 < size) ? iter + key - 1 : size - 1;
        reverse(arr, iter, end);
    }
}
