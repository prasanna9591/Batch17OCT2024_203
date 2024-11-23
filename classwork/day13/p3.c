#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_LINE_LENGTH 100

// Define the structure for an employee
struct Employee {
    int id;
    char name[50];
    char gender;
    int phone;
    float salary;
};

int main() {
    FILE *file;
    struct Employee employees[MAX_EMPLOYEES];
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Open the file in read mode
    file = fopen("Db.txt", "r");
    if (file == NULL) {
        perror("fopen: ");
        exit(1);
    }

    // Read the employee records from the file
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%c|%d|%f", &employees[count].id, employees[count].name, &employees[count].gender, &employees[count].phone, &employees[count].salary);
        count++;
    }

    // Close the file
    fclose(file);

    // Print the employee records exactly as they are in the file
    printf("Employee Records:\n");
    for (int i = 0; i < count; i++) {
        printf("%d|%s|%c|%d|%.0f\n", employees[i].id, employees[i].name, employees[i].gender, employees[i].phone, employees[i].salary);
    }

    return 0;
}

