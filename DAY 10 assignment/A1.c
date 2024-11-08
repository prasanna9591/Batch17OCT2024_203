/*
    DESC:Check whether a given number can be expressed as the sum of two prime number
	
    By :Prasanna
	
    Date :7th,Nov 2024

*/

#include<stdio.h>
#include <stdlib.h>

int prime(int num);

void check_sum(int num);


int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    check_sum(num);

    return 0;
}
int prime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) 
            return 0;
    }
    return 1;
}
void check_sum(int num) 
{
    int flag = 0;
    int iter;
    int count;
    for (iter = 2; iter <= num / 2; iter++) 
    {
        if (prime(iter) && prime(num - iter))
        {
            printf("%d = %d + %d\n", num, iter, num - iter);
            flag = 1;
            count++;
        }
    }
    if (!flag) 
    {
        printf("%d cannot be expressed as the sum of two prime numbers.\n", num);
    }
    printf("\n NO OF WAYS = %d",count);
}
