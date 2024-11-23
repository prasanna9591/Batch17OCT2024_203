/* 
1a. function readdisplay() to read the following data types 
only one at a time at run time and to display.
1. char type 2. integer type
3. char array of maximum 80 characters
4. short type
5. float type
TestData:
‘c’, 8978, “hello”, 8, 45.678
‘H’, 254, “hello Hi How”, 256, 145.2678
*/
#include <stdio.h>
int main() {
    printf("Data Test 1:\n");
    readdisplay();

    printf("\n Data Test 2:\n");
    readdisplay();

    return 0;
}
void readdisplay() {
    char charType;
    int intType;
    char charArray[80];
    short shortType;
    float floatType;

    printf("Enter a character: ");
    scanf(" %c", &charType);
    printf("The character: %c\n", charType);

    printf("Enter an integer: ");
    scanf("%d", &intType);
    printf("The integer: %d\n", intType);

    printf("Enter a string: ");
    scanf(" %79[^\n]", charArray);
    printf("The string: %s\n", charArray);

    printf("Enter a short integer: ");
    scanf("%hd", &shortType);
    printf("The short integer value: %hd\n", shortType);

    printf("Enter a float: ");
    scanf("%f", &floatType);
    printf("The float value: %f\n", floatType);
}

