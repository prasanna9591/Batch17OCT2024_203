#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    FILE *sourceFile = NULL, *destFile = NULL;
    char ch;
    char sourcePath[] = "Test2.txt";
    char destPath[] = "CopyOfTest2.txt";

    // Open source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) 
	{
        perror("fopen: ");
        printf("\n%p\n\n", sourceFile);
        exit(1);
    }
    printf("\nOpened the source file successfully %p\n\n", sourceFile);

    // Open destination file in write mode
    destFile = fopen(destPath, "w");
    if (destFile == NULL) 
	{
        perror("fopen: ");
        fclose(sourceFile);
        printf("\n%p\n\n", destFile);
        exit(1);
    }
    printf("\nOpened the destination file successfully %p\n\n", destFile);

    // Copy contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) 
	{
        fputc(ch, destFile);
    }

    printf("\nFile copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

