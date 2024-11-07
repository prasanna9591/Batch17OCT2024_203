/*
	DESC :Printing alphabet and number triangle
	
	NAME :Prasanna
	
	Date :7th,Nov 2024

*/
#include <stdio.h>

void alpbt_tri(int num);
void num_tri(int num);

int main()
{
    int num;
    printf("Enter the number of rows: ");
    scanf("%d", &num);

    printf("\nAlphabet Triangle:\n");
    alpbt_tri(num);

    printf("\nNumber Triangle:\n");
    num_tri(num);

    return 0;
}

void alpbt_tri(int num) 
{
    int iter1, iter2;
    
    for (iter1 = 0; iter1 < num; iter1++) 
    {
        for (iter2 = 0; iter2 < num - iter1 - 1; iter2++) 
        {
            printf(" ");
        }
        for (iter2 = 0; iter2 <= iter1; iter2++) 
        {
            printf("%c", 'A' + iter2);
        }
        for (iter2 = iter1 - 1; iter2 >= 0; iter2--) 
        {
            printf("%c", 'A' + iter2);
        }
        printf("\n");
    }
}

// Function to print the number triangle
void num_tri(int num) 
{
    int iter1, iter2;
    
    for (iter1 = 0; iter1 < num; iter1++) 
    {
        for (iter2 = 0; iter2 < num - iter1 - 1; iter2++) 
        {
            printf(" ");
        }
        for (iter2 = 1; iter2 <= iter1 + 1; iter2++) 
        {
            printf("%d", iter2);
        }
        for (iter2 = iter1; iter2 >= 1; iter2--) 
        {
            printf("%d", iter2);
        }
        printf("\n");
    }
}
