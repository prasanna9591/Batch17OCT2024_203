#include <stdio.h>
#include <stdbool.h>

bool prime(int num) 
{
    while (num > 0) 
    {
        int digit = num % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7) 
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

int number(int n) {
    int count = 0;
    int num = 1;
    while (true) {
        if (prime(num)) {
            count++;
            if (count == n) {
                return num;
            }
        }
        num++;
    }
}

int main() {
    int T, N;
    int iter;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    for (iter = 0; iter < T; iter++) {
        printf("Enter the value of N: ");
        scanf("%d", &N);
        printf("%d\n", number(N));
    }
    return 0;
}
