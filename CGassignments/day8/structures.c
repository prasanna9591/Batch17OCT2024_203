Structure and Functions-

1. Refer the code in “student.c”. Implement the following requirements.

a. Change the name member to char * datatype

b. Add 2 functions below to read and store name and percentage scores from user in student record.

//pass name address as parameter and read and update name field Return updated name

char *read_update_name(char *name);

//pass address of percentage as parameter, read and update percentage field of student record. Also return updated percentage

int read_update_percentage(int *percent);

c. Check for memory leaks

d. Specify atleast 5 dataset used for testing

Check for memory leak.

Ans: To check for memory leaks, we are dynamically allocating memory for the name using malloc. After using the name, we free
it using free(student.name) to ensure that there are no memory leaks.

further verify, you can run this code with tools like Valgrind (on Linux) to check for memory leaks:

valgrind ./student_program

Code:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Student
typedef struct {
    char *name;  // Name as a pointer to char
    int percentage;  // Percentage as an integer
} Student;

// Function prototypes
char *read_update_name(char *name);
int read_update_percentage(int *percent);
void display_student_details(Student student);

int main() {
    // Create an instance of the Student structure
    Student student;

    // Read and update the name and percentage
    student.name = read_update_name(NULL);  // Initially NULL, will allocate inside function
    read_update_percentage(&student.percentage);

    // Display student details
    display_student_details(student);

    // Free allocated memory
    free(student.name);  // Free dynamically allocated memory for the name

    return 0;
}

// Function to read and update the student's name
char *read_update_name(char *name) {
    char temp_name[100];  // Temporary buffer for user input

    // Read the name from the user
    printf("Enter student's name: ");
    fgets(temp_name, sizeof(temp_name), stdin);
    temp_name[strcspn(temp_name, "\n")] = '\0';  // Remove the newline character from the input

    // Allocate memory for the name and copy the input
    name = (char *)malloc(strlen(temp_name) + 1);
    if (name != NULL) {
        strcpy(name, temp_name);
    } else {
        printf("Memory allocation failed for name.\n");
        exit(1);  // Exit program if memory allocation fails
    }

    return name;  // Return the updated name
}

// Function to read and update the student's percentage
int read_update_percentage(int *percent) {
    printf("Enter student's percentage: ");
    scanf("%d", percent);
    
    return *percent;  // Return the updated percentage
}

// Function to display student details
void display_student_details(Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Percentage: %d\n", student.percentage);
}







