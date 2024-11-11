#include <stdio.h>

void printNumber(int num) {
    if (num == 0) {
        putchar('0');
        return;
    }

    char buffer[10];
    int i = 0;

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0) {
        putchar(buffer[--i]);
    }
}

void printMultiplicationTable(int n) {
    int i = 1, j;

    do {
        j = 1;
        do {
            printNumber(n);
            putchar('*');
            printNumber(j);
            putchar('=');
            printNumber(n * j);
            putchar('\n');
            j++;
        } while (j <= 10);
        i++;
    } while (i <= 1);
}

int main() {
    int n = 2; // Change this value to print a different multiplication table
    printMultiplicationTable(n);
    return 0;
}


