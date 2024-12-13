/*
1c. display the char array content in upper case
*/

#include <stdio.h>
#include <ctype.h> 
int main() {

    printf("Test Data 1:\n");
    readdisplay2();
    
	printf("\nTest Data 2:\n");
    readdisplay2();
    return 0;
}
void readdisplay2() 
{
    char charArray[80];
    printf("Enter a string: ");
    scanf("%s",  charArray);
    for (int i = 0; charArray[i] != '\0'; i++) 
	{
        charArray[i] = toupper(charArray[i]);
    }
    printf("Entered string: %s\n", charArray);
}
