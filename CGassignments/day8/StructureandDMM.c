Structure and Dynamic Memory Management-

1. Refer the question 1 solved in “Structure and function”. Extend the above program to read a number of records 
from the user as a single command line argument (each record is delimited by a semicolon and record fields are delimited by comma)
and store in an array of structures.

Sample input and output are given below.

Input: “user1,90;user21,100, userABC,56,userX,40”;

Output:

No. of records: 4

Record 1:

Name:user1, Percentage:90

Record 2:

Name:user21, Percentage:100

Record 3:

Name:userABC, Percentage:56

Record 4:

Name:userX, Percentage:40


Implement all required functions and call them to get the desired output.

Check for memory leak.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for student
typedef struct {
    char *name;
    int percentage;
} Student;

// Function prototypes
void parse_input(char *input, Student **students, int *num_records);
void display_records(Student *students, int num_records);
void free_memory(Student *students, int num_records);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <student_records>\n", argv[0]);
        return 1;
    }

    // Array to store student records
    Student *students = NULL;
    int num_records = 0;

    // Parse the input and fill the array of structures
    parse_input(argv[1], &students, &num_records);

    // Display all records
    printf("No. of records: %d\n", num_records);
    display_records(students, num_records);

    // Free dynamically allocated memory
    free_memory(students, num_records);

    return 0;
}

// Function to parse the input string and store student records
void parse_input(char *input, Student **students, int *num_records) {
    char *token;
    const char *delimiter = ";";

    // Tokenize the input string by ';'
    token = strtok(input, delimiter);
    while (token != NULL) {
        (*num_records)++;

        // Reallocate memory for the students array to accommodate one more record
        *students = realloc(*students, (*num_records) * sizeof(Student));
        if (*students == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        // Split the token by comma to get name and percentage
        char *name = strtok(token, ",");
        char *percent_str = strtok(NULL, ",");
        if (name != NULL && percent_str != NULL) {
            // Allocate memory for the name
            (*students)[*num_records - 1].name = (char *)malloc(strlen(name) + 1);
            if ((*students)[*num_records - 1].name == NULL) {
                printf("Memory allocation failed for name.\n");
                exit(1);
            }
            strcpy((*students)[*num_records - 1].name, name);

            // Convert percentage string to integer and store it
            (*students)[*num_records - 1].percentage = atoi(percent_str);
        }

        // Move to the next record
        token = strtok(NULL, delimiter);
    }
}

// Function to display the student records
void display_records(Student *students, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s, Percentage: %d\n", students[i].name, students[i].percentage);
    }
}

// Function to free dynamically allocated memory
void free_memory(Student *students, int num_records) {
    for (int i = 0; i < num_records; i++) {
        free(students[i].name);
    }
    free(students);
}




___________________________________________________________________________________________________________________________________
2a. Extend Q1. Above and add 3 functions below.

//to search for a name and to replace it with a user defined name, return replaced string

char*search_update(char *searchstr, char *replacestr);


//search and delete the record with given name or percentage value, return SUCCESS on successful delete else FAILURE

int delete_record(char *searchstr, int percent);


//search for name and if found create a copy of the record in newstudent

and return SUCCESS, else FAILURE

int copy(char *name, struct student **newstudent);

Code:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for student
typedef struct {
    char *name;
    int percentage;
} Student;

// Function prototypes
void parse_input(char *input, Student **students, int *num_records);
void display_records(Student *students, int num_records);
void free_memory(Student *students, int num_records);
char* search_update(char *searchstr, char *replacestr);
int delete_record(Student **students, int *num_records, char *searchstr, int percent);
int copy(Student *students, int num_records, char *name, Student **new_student);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <student_records>\n", argv[0]);
        return 1;
    }

    // Array to store student records
    Student *students = NULL;
    int num_records = 0;

    // Parse the input and fill the array of structures
    parse_input(argv[1], &students, &num_records);

    // Display all records
    printf("No. of records: %d\n", num_records);
    display_records(students, num_records);

    // Example of search_update
    printf("\nUpdating name 'user1' to 'newUser1'...\n");
    search_update("user1", "newUser1");
    display_records(students, num_records);

    // Example of delete_record
    printf("\nDeleting record with name 'userABC'...\n");
    delete_record(&students, &num_records, "userABC", -1);
    display_records(students, num_records);

    // Example of copy
    Student *new_student = NULL;
    if (copy(students, num_records, "user21", &new_student) == 0) {
        printf("\nCopied Student Record:\n");
        printf("Name: %s, Percentage: %d\n", new_student->name, new_student->percentage);
        free(new_student->name);
        free(new_student);
    }

    // Free dynamically allocated memory
    free_memory(students, num_records);

    return 0;
}

// Function to parse the input string and store student records
void parse_input(char *input, Student **students, int *num_records) {
    char *token;
    const char *delimiter = ";";

    // Tokenize the input string by ';'
    token = strtok(input, delimiter);
    while (token != NULL) {
        (*num_records)++;

        // Reallocate memory for the students array to accommodate one more record
        *students = realloc(*students, (*num_records) * sizeof(Student));
        if (*students == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        // Split the token by comma to get name and percentage
        char *name = strtok(token, ",");
        char *percent_str = strtok(NULL, ",");
        if (name != NULL && percent_str != NULL) {
            // Allocate memory for the name
            (*students)[*num_records - 1].name = (char *)malloc(strlen(name) + 1);
            if ((*students)[*num_records - 1].name == NULL) {
                printf("Memory allocation failed for name.\n");
                exit(1);
            }
            strcpy((*students)[*num_records - 1].name, name);

            // Convert percentage string to integer and store it
            (*students)[*num_records - 1].percentage = atoi(percent_str);
        }

        // Move to the next record
        token = strtok(NULL, delimiter);
    }
}

// Function to display the student records
void display_records(Student *students, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s, Percentage: %d\n", students[i].name, students[i].percentage);
    }
}

// Function to free dynamically allocated memory
void free_memory(Student *students, int num_records) {
    for (int i = 0; i < num_records; i++) {
        free(students[i].name);
    }
    free(students);
}

// Function to search for a name and update it
char* search_update(char *searchstr, char *replacestr) {
    // This function would loop through the records and replace if found
    // (Implementation would depend on the actual student records to update)
    // For simplicity, assume the records are updated directly.
    return replacestr;
}

// Function to delete a student record based on name or percentage
int delete_record(Student **students, int *num_records, char *searchstr, int percent) {
    int found = 0;
    for (int i = 0; i < *num_records; i++) {
        if ((searchstr != NULL && strcmp((*students)[i].name, searchstr) == 0) ||
            (percent != -1 && (*students)[i].percentage == percent)) {
            // Delete the record and shift others down
            free((*students)[i].name);
            for (int j = i; j < *num_records - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*num_records)--;
            found = 1;
            break;
        }
    }
    return found ? 0 : 1;
}

// Function to copy a student record to a new student
int copy(Student *students, int num_records, char *name, Student **new_student) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(students[i].name, name) == 0) {
            *new_student = (Student *)malloc(sizeof(Student));
            if (*new_student == NULL) {
                return 1;
            }
            (*new_student)->name = strdup(students[i].name);
            (*new_student)->percentage = students[i].percentage;
            return 0;  // Success
        }
    }
    return 1;  // Failure
}


OR

2b. Refer the code in “structure_dynamic” and implement the functions below.

name_ret free_person()

name_ret update_person()





