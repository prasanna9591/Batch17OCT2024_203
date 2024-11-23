Arrays and Pointers:

1. What does the code below refer to? Extend the code and demonstrate the use of ptr to access the contents of a 2D array.

int (*ptr)[4];

Referring the sample code in "array_ptr_simple.c"

#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/
int main()
{
	int arr[][3]= {1,2,3,4,5,6};
	{
	    	printf("\n  1: %d %d", arr[1][0], arr[0][2]);
	}
	
	{
        //using a single pointer
	    int *ptr = arr[1];
	  	printf("\n 2:  %d %d %d", *(ptr+0), *(ptr+1), *(ptr+2));
	}
	{
        //using an array of 3 pointers
	    int *ptr2[3]; //array of 3 pointers
	    ptr2[0] = &arr[0][0];
	    ptr2[1] = &arr[0][1];
	    ptr2[2] = &arr[0][2];
	    printf("\n 3:  %d %d %d", *ptr2[0], *ptr2[1], *ptr2[2]);
	}
    {
        //using an array of 2 pointers with each pointer pointing to an array of integers
        int (*ptr3)[2]; //pointer to an array of integers
        ptr3 = arr[0];// first row 
        printf("\n 4: %d %d %d", (*ptr3)[0], (*ptr3)[1], (*ptr3)[2]);
        ptr3++;
        printf("\n 4: %d %d %d", (*ptr3)[0], (*ptr3)[1], (*ptr3)[2]);
    }
}
__________________________________________________________________________________________________
1A:
#include <stdio.h>
#include <stdlib.h>
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/


int main()
{
    int arr[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
    int (*ptr)[4]; // pointer to an array of 4 integers

    ptr = arr; // ptr now points to the first row of arr

    // Accessing elements using ptr
    printf("\nUsing ptr to access 2D array elements:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("arr[%d][%d] = %d\n", i, j, ptr[i][j]);
        }
    }

    return 0;
}
____________________________________________________________________________________________________

3. Refer the code snippet below. Implement the function search_insert() as mentioned in the code.

#define MAX 80


//search for the given char and if found, then create space for 1 character and insert ‘_’ after the searched character.
 Let the remaining characters in the input be placed after ‘_’.

int search_insert(char name[], char search_char);
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/



int main()

{

char name[MAX]=”ABC”;

char *ptr = name;

int ret = search_insert(name, search_char);


if (ret == SUCCESS)

{

//display updated string

}

}

Ans:#include <stdio.h>
#include <string.h>
#define MAX 80
#define SUCCESS 1
#define FAILURE 0

/**************************************************************************
*
* FUNCTION NAME: search_insert
*
* DESCRIPTION:  function searches for 'B' in the string, finds it, and inserts an underscore after it
*
* RETURNS: Updated String
**************************************************************************/



int search_insert(char name[], char search_char) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (name[i] == search_char) {
            // Shift characters to the right to make space for '_'
            for (int j = len; j > i; j--) {
                name[j + 1] = name[j];
            }
            // Insert '_'
            name[i + 1] = '_';
            return SUCCESS;
        }
    }
    return FAILURE;
}

int main() {
    char name[MAX] = "ABC";
    char search_char = 'B';
    int ret = search_insert(name, search_char);

    if (ret == SUCCESS) {
        printf("Updated string: %s\n", name);
    } else {
        printf("Character not found.\n");
    }

    return 0;
}


______________________________________________________________________________________
4. Refer the program “array_ptr_repr_partial.c”. Implement the functions below which are yet to be implemented in code.

int func1(int (*ptr)[3]); // pointer to array, second dimension is explicitly specified

int func2(int **ptr); // double pointer, using an auxiliary array of pointers

4A: #include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/

int func1(int (*ptr)[3]);
int func2(int **);

int main() {
    int mat[3][3], i, j;
    int k = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            mat[i][j] = k++;
        }

    printf("Initialized data to: ");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%p   ", &mat[i][j]);
            printf("%d  ", mat[i][j]);
        }
    }
    printf("\n");

    func1(mat);

    // Convert mat to double pointer for func2
    int *ptr[3];
    for (i = 0; i < 3; i++) {
        ptr[i] = mat[i];
    }
    func2(ptr);

    return 0;
}

int func1(int (*ptr)[3]) {
    printf("Inside func1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int func2(int **ptr) {
    int rows = 3, cols = 3;
    int **aux = (int **)malloc(rows * sizeof(int *));
    if (aux == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        aux[i] = (int *)malloc(cols * sizeof(int));
        if (aux[i] == NULL) {
            printf("Memory allocation failed\n");
            return -1;
        }
    }

    // Copy data from ptr to aux
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            aux[i][j] = ptr[i][j];
        }
    }

    // Print the copied data to verify
    printf("Inside func2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(aux[i]);
    }
    free(aux);

    return 0;
}

__________________________________________________________________________________________________

5. Refer the program “array_dbl_pointers_function_partial.c”. Implement the missing functionality in the code marked with TBD1, TBD2…..

#include <stdio.h>
#include <stdlib.h>
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/

void func1(int (*ptr)[3]);
void func2(short (*mat)[3]);

int main() {
    int mat[3][3], i, j;
    int k = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            mat[i][j] = k++;
        }

    printf("Initialized data to: ");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%p   ", &mat[i][j]);
            printf("%d  ", mat[i][j]);
        }
    }
    printf("\n");

    func1(mat);

    // Convert mat to short for func2
    short mat_short[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat_short[i][j] = (short)mat[i][j];
        }
    }
    func2(mat_short);

    return 0;
}

void func1(int (*ptr)[3]) {
    printf("Inside func1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void func2(short (*mat)[3]) {
    register short i, j;

    printf(" Declare as pointer to column, explicitly specify 2nd dim: ");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%d  ", mat[i][j]); // Display the element
        }
    }
    printf("\n");
}

__________________________________________________________________________________________________

6. Refer the program "pointer_example.c". Fix the warning issue

referring "pointer_example.c" 
#include <stdio.h>
#include <stdlib.h>
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/

int main()
{
    char arr[]="ABC";
	
	char *ptr = (char*)&arr;
	printf("%p %p", arr, ptr);
	printf("\n 1 %c %c", *ptr, *(ptr+1));
	
    char msg[][5] = {"AB", "gh", "er"};
	char (*ptr2)[2];
	
	ptr2 = &msg[0];
	printf("%p %p", msg, ptr2);
	printf("\n 2 %c %c", (*ptr2)[0], (*ptr2)[1]);
	
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[] = "ABC";
    
    char *ptr = (char*)&arr;
    printf("%p %p", (void*)arr, (void*)ptr);
    printf("\n 1 %c %c", *ptr, *(ptr+1));
    
    char msg[][5] = {"AB", "gh", "er"};
    char (*ptr2)[5];
    
    ptr2 = msg;
    printf("%p %p", (void*)msg, (void*)ptr2);
    printf("\n 2 %c %c", (*ptr2)[0], (*ptr2)[1]);
    
    return 0;
}

_____________________________________________________________________________________________________

7. Consider an array of strings as below.

char arr[][10]={"Word", "Excel", "PowerPoint", "Pdf", "Paint"};

a. Implement a function read_displaystring() to read a row index from the user, access the string, store in a char * variable and using this, 
traverse every alternate character in the string and display in console.

void read_displaystring(char *arr[][10], int row);

b. Reverse the string read at the index in a) using a function of prototype as below. Caller to read the returned string and display the 
reversed string. [Ensure that the input source array is not corrupted and remaining elements are intact].

char *reverse(char *arr[][10], int row);

ans: #include <stdio.h>

void read_displaystring(char arr[][10], int row) {
    char *str = arr[row];
    printf("Alternate characters in the string: ");
    for (int i = 0; str[i] != '\0'; i += 2) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char arr[][10] = {"Word", "Excel", "PowerPoint", "Pdf", "Paint"};
    int row;
    printf("Enter row index: ");
    scanf("%d", &row);
    if (row >= 0 && row < 5) {
        read_displaystring(arr, row);
    } else {
        printf("Invalid row index.\n");
    }
    return 0;
}

b. #include <string.h>

char* reverse(char arr[][10], int row) {
    static char reversed[10];
    char *str = arr[row];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

int main() {
    char arr[][10] = {"Word", "Excel", "PowerPoint", "Pdf", "Paint"};
    int row;
    printf("Enter row index: ");
    scanf("%d", &row);
    if (row >= 0 && row < 5) {
        read_displaystring(arr, row);
        char *reversed_str = reverse(arr, row);
        printf("Reversed string: %s\n", reversed_str);
    } else {
        printf("Invalid row index.\n");
    }
    return 0;
}
