/*

Operators Associativity and Precedence Assignment

1. Use operator associativity, evaluate the following expressions 
and predict the output

a. x = 34 + 12/4 – 56
b. 12 + 3 - 4 / 2 < 3 + 1
c. (2 + (3 + 2) ) * 10
d. 34 + 12/4 – 45

*/
#include <stdio.h>

int main() 
{
    int x = 34 + 12 / 4 - 56;
    printf("x = 34 + 12 / 4 - 56 = %d\n", x); 
    
	int result_b = 12 + 3 - 4 / 2 < 3 + 1;
    printf(" 12 + 3 - 4 / 2 < 3 + 1 = %d\n", result_b); 
    
	int result_c = (2 + (3 + 2)) * 10;
    printf(" (2 + (3 + 2)) * 10 = %d\n", result_c); 
    
	int result_d = 34 + 12 / 4 - 45;
    printf(" 34 + 12 / 4 - 45 = %d\n", result_d);
    
	return 0;
}

