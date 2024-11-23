/*
1d. Add code to display the size of each data type mentioned in Q1a and sizeof the variables of each datatype (You may refer sample code in data_type_size.c )
*/

#include <stdio.h>
#include <ctype.h> 
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

    printf("Enter a character, an integer, a string, a short integer, and a float: ");
    scanf(" %c %d %79s %hd %f", &charType, &intType, charArray, &shortType, &floatType);

    for (int i = 0; charArray[i] != '\0'; i++) 
	{
        charArray[i] = toupper(charArray[i]);
    }

    printf("Entered character: %c\n", charType);
    printf("Entered integer: %d\n", intType);
    printf("Entered string: %s\n", charArray);
    printf("Entered short integer: %hd\n", shortType);
    printf("Entered float: %f\n", floatType);

    printf("\nSize of data types:\n");
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char array: %zu bytes\n", sizeof(charArray));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of float: %zu bytes\n", sizeof(float));

    printf("\nSize of variables:\n");
    printf("Size of charType: %zu bytes\n", sizeof(charType));
    printf("Size of intType: %zu bytes\n", sizeof(intType));
    printf("Size of charArray: %zu bytes\n", sizeof(charArray));
    printf("Size of shortType: %zu bytes\n", sizeof(shortType));
    printf("Size of floatType: %zu bytes\n", sizeof(floatType));
}
