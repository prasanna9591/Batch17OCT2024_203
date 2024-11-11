/*
DESC:
for loop as exit controlled loop
*/
#include<stdio.h>
int main()
{
for (int i = 5;; i++) 
{
    printf("%d\n", i);
    if (i >= 4)
	{
        break;
    }
}

}
