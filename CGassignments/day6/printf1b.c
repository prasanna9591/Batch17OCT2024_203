/* 
1b. Create a copy of readdisplay() as function readdisplay2() 
with changes below
--> Instead of reading 1 data at a time, 
read all inputs using a single scanf().
Test readdisplay2() by changing the read order. Do you observe any issue?
*/

#include <stdio.h>
int main() 
{    
	printf("Test Data 1:\n");
    readdisplay2();
    printf("\nTest Data 2:\n");
    readdisplay2();
    return 0;
}

void readdisplay2() 
{
    char charType;
    int intType;
    char charArray[80];
    short shortType;
    float floatType;
    
	printf("Enter a char, an integer, a string (max 80 characters), a short integer, and a float: ");
    scanf(" %c %d %79s %hd %f", &charType, &intType, charArray, &shortType, &floatType);

    printf("You entered char: %c\n", charType);
    printf("You entered integer: %d\n", intType);
    printf("You entered string: %s\n", charArray);
    printf("You entered short integer: %hd\n", shortType);
    printf("You entered float: %f\n", floatType);
}
