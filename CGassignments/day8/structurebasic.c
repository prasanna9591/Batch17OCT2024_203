Structure basics-

1. WAP to define read and store the following details together in a structure and display the structure details

name – char* [input could of maximum length 50 char]

age – uint

designation – enum [use the enum values used in enum exercise]

void read (EMP *emp)

void display (EMP emp);

Implement additional function below.

//read and update the employee record

int update(EMP *emp);

//copy the emp to a new employee and return

EMP copy(EMP emp);

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Enum to store employee designations
typedef enum {
    MANAGER,
    DEVELOPER,
    ANALYST,
    TESTER
} Designation;

// Structure to store employee details
typedef struct {
    char *name;
    uint32_t age;
    Designation designation;
} EMP;

// Function prototypes
void read(EMP *emp);
void display(EMP emp);
int update(EMP *emp);
EMP copy(EMP emp);

int main() {
    EMP emp1;

    // Read employee details
    read(&emp1);

    // Display employee details
    display(emp1);

    // Update employee details
    if (update(&emp1)) {
        printf("Employee details updated successfully.\n");
    } else {
        printf("Invalid input for update.\n");
    }

    // Copy employee record
    EMP emp2 = copy(emp1);
    printf("\nCopied Employee Record:\n");
    display(emp2);

    return 0;
}

// Function to read employee details
void read(EMP *emp) {
    char name[50];
    int designation;
    
    printf("Enter employee name (max 50 characters): ");
    fgets(name, sizeof(name), stdin);  // Read name input
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    // Assign dynamic memory for name
    emp->name = (char *)malloc(strlen(name) + 1);
    if (emp->name != NULL) {
        strcpy(emp->name, name);
    }

    printf("Enter age: ");
    scanf("%u", &emp->age);

    printf("Enter designation (0: MANAGER, 1: DEVELOPER, 2: ANALYST, 3: TESTER): ");
    scanf("%d", &designation);
    if (designation >= 0 && designation <= 3) {
        emp->designation = (Designation)designation;
    } else {
        emp->designation = MANAGER;  // Default designation
        printf("Invalid designation. Defaulting to MANAGER.\n");
    }
}

// Function to display employee details
void display(EMP emp) {
    const char *designationStrings[] = {"MANAGER", "DEVELOPER", "ANALYST", "TESTER"};

    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Designation: %s\n", designationStrings[emp.designation]);
}

// Function to update employee details
int update(EMP *emp) {
    char name[50];
    int designation;

    printf("Update employee name (max 50 characters): ");
    getchar();  // Clear the newline character from the previous input
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    // Update name
    free(emp->name);  // Free previously allocated memory
    emp->name = (char *)malloc(strlen(name) + 1);
    if (emp->name != NULL) {
        strcpy(emp->name, name);
    }

    printf("Update age: ");
    scanf("%u", &emp->age);

    printf("Update designation (0: MANAGER, 1: DEVELOPER, 2: ANALYST, 3: TESTER): ");
    scanf("%d", &designation);
    if (designation >= 0 && designation <= 3) {
        emp->designation = (Designation)designation;
        return 1;
    } else {
        printf("Invalid designation. No changes made.\n");
        return 0;
    }
}

// Function to copy employee record to a new employee
EMP copy(EMP emp) {
    EMP newEmp;
    newEmp.name = (char *)malloc(strlen(emp.name) + 1);
    if (newEmp.name != NULL) {
        strcpy(newEmp.name, emp.name);
    }
    newEmp.age = emp.age;
    newEmp.designation = emp.designation;
    return newEmp;
}

______________________________________________________________________________________________________________________________________________
2. Extend the above program and create and initialize an array of 3 structures. Reuse the read() and display() functions to read, initialize and 
display structures.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NUM_EMPLOYEES 3

// Enum to store employee designations
typedef enum {
    MANAGER,
    DEVELOPER,
    ANALYST,
    TESTER
} Designation;

// Structure to store employee details
typedef struct {
    char *name;
    uint32_t age;
    Designation designation;
} EMP;

// Function prototypes
void read(EMP *emp);
void display(EMP emp);
int update(EMP *emp);
EMP copy(EMP emp);

int main() {
    EMP employees[NUM_EMPLOYEES];

    // Read details for all employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        read(&employees[i]);
    }

    // Display details for all employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        display(employees[i]);
    }

    // Optionally, update a record (e.g., Employee 1)
    printf("\nUpdating Employee 1:\n");
    if (update(&employees[0])) {
        printf("Employee 1 details updated successfully.\n");
    }

    // Display updated employee details
    printf("\nUpdated Employee 1 details:\n");
    display(employees[0]);

    // Copy the first employee to a new employee record
    EMP empCopy = copy(employees[0]);
    printf("\nCopied Employee Record:\n");
    display(empCopy);

    // Free dynamically allocated memory for all employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        free(employees[i].name);
    }

    free(empCopy.name);  // Free the copied employee's name

    return 0;
}

// Function to read employee details
void read(EMP *emp) {
    char name[50];
    int designation;
    
    printf("Enter employee name (max 50 characters): ");
    fgets(name, sizeof(name), stdin);  // Read name input
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    // Assign dynamic memory for name
    emp->name = (char *)malloc(strlen(name) + 1);
    if (emp->name != NULL) {
        strcpy(emp->name, name);
    }

    printf("Enter age: ");
    scanf("%u", &emp->age);

    printf("Enter designation (0: MANAGER, 1: DEVELOPER, 2: ANALYST, 3: TESTER): ");
    scanf("%d", &designation);
    if (designation >= 0 && designation <= 3) {
        emp->designation = (Designation)designation;
    } else {
        emp->designation = MANAGER;  // Default designation
        printf("Invalid designation. Defaulting to MANAGER.\n");
    }

    getchar();  // Clear newline character from buffer after reading integer
}

// Function to display employee details
void display(EMP emp) {
    const char *designationStrings[] = {"MANAGER", "DEVELOPER", "ANALYST", "TESTER"};

    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Designation: %s\n", designationStrings[emp.designation]);
}

// Function to update employee details
int update(EMP *emp) {
    char name[50];
    int designation;

    printf("Update employee name (max 50 characters): ");
    getchar();  // Clear the newline character from the previous input
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    // Update name
    free(emp->name);  // Free previously allocated memory
    emp->name = (char *)malloc(strlen(name) + 1);
    if (emp->name != NULL) {
        strcpy(emp->name, name);
    }

    printf("Update age: ");
    scanf("%u", &emp->age);

    printf("Update designation (0: MANAGER, 1: DEVELOPER, 2: ANALYST, 3: TESTER): ");
    scanf("%d", &designation);
    if (designation >= 0 && designation <= 3) {
        emp->designation = (Designation)designation;
        return 1;
    } else {
        printf("Invalid designation. No changes made.\n");
        return 0;
    }
}

// Function to copy employee record to a new employee
EMP copy(EMP emp) {
    EMP newEmp;
    newEmp.name = (char *)malloc(strlen(emp.name) + 1);
    if (newEmp.name != NULL) {
        strcpy(newEmp.name, emp.name);
    }
    newEmp.age = emp.age;
    newEmp.designation = emp.designation;
    return newEmp;
}
