/*
    DESC :Write a program to find the  n-th number made of prime digits
	
	NAME :Prasanna
	
	Date :7th,Nov 2024

*/
#include <stdio.h>
#include <string.h>

void find(int num, char* result);

int main() 
{
    int T, N;
    int iter;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (iter = 0; iter < T; iter++) 
    {
        printf("Enter the value of N: ");
        scanf("%d", &N);

        char nth_number[20];
        find(N, nth_number);

        printf("The %dth number made of prime digits is: %s\n", N, nth_number);
    }

    return 0;
}
void find(int num, char* result)
{
    char prime_digits[] = "2357";
    int index = 0;
    int iter;

    while (num > 0) 
    {
        result[index++] = prime_digits[(num - 1) % 4];
        num = (num - 1) / 4;
    }
    result[index] = '\0';

    for (iter = 0; iter < index / 2; iter++) 
    {
        char temp = result[iter];
        result[iter] = result[index - iter - 1];
        result[index - iter - 1] = temp;
    }
}
