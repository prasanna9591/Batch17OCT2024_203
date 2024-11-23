#include <stdio.h>
#include <stdlib.h>

// Define the structure for an employee using typedef
typedef struct {
    int id;
    char name[50];
    char gender;
    int phone;
    float salary;
} EMP;

int main() {
    FILE *file;
    EMP *employees = NULL;
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read;
    int count = 0;
    int capacity = 10; // Initial capacity

    // Allocate initial memory for employees
    employees = (EMP *)malloc(capacity * sizeof(EMP));
    if (employees == NULL) {
        perror("malloc: ");
        exit(1);
    }

    // Open the file in read mode
    file = fopen("Db.txt", "r");
    if (file == NULL) {
        perror("fopen: ");
        free(employees);
        exit(1);
    }

    // Read the employee records from the file
    while ((read = getline(&line, &line_length, file)) != -1) {
        if (count >= capacity) {
            // Reallocate memory if capacity is exceeded
            capacity *= 2;
            employees = (EMP *)realloc(employees, capacity * sizeof(EMP));
            if (employees == NULL) {
                perror("realloc: ");
                fclose(file);
                free(line);
                exit(1);
            }
        }
        sscanf(line, "%d|%[^|]|%c|%d|%f", &employees[count].id, employees[count].name, &employees[count].gender, &employees[count].phone, &employees[count].salary);
        count++;
    }

    // Close the file
    fclose(file);
    free(line);

    // Print the employee records exactly as they are in the file
    printf("Employee Records:\n");
    for (int i = 0; i < count; i++) {
        printf("%d|%s|%c|%d|%.0f\n", employees[i].id, employees[i].name, employees[i].gender, employees[i].phone, employees[i].salary);
    }

    // Free the allocated memory
    free(employees);

    return 0;
}

