#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for employee records
struct Employee 
{
    int id;
    char firstName[50];
    char lastName[50];
    char title[5];
    float salary;
};

// Function prototypes
void scanEmployee(struct Employee *employee);
void displayEmployee(struct Employee employee);
int searchById(struct Employee *employees, int count, int id);
int searchByLastName(struct Employee *employees, int count, char *lastName);
void searchBySalaryRange(struct Employee *employees, int count, float minSalary, float maxSalary);
void updateLastName(struct Employee *employee, char *lastName);
void menu(struct Employee **employees, int *count);

int main()
{
    struct Employee *employees = NULL;
    int count = 0;

    menu(&employees, &count);

    // Free the allocated memory
    free(employees);

    return 0;
}

void menu(struct Employee **employees, int *count)
{
    int choice, subChoice, id, index;
    char lastName[50];
    float minSalary, maxSalary;

    while (1)
	{
        printf("\nMain Menu:\n");
        printf("1. Update Employee Details or Display Existing Employees\n");
        printf("2. Change Search Values\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
		{
            case 1:
                printf("\nSub Menu:\n");
                printf("1. Add New Employee\n");
                printf("2. Display All Employees\n");
                printf("3. Search Employee by ID\n");
                printf("4. Search Employee by Last Name\n");
                printf("5. Search Employees by Salary Range\n");
                printf("6. Update Employee Last Name\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice)
				{
                    case 1:
                        *employees = realloc(*employees, (*count + 1) * sizeof(struct Employee));
                        if (*employees == NULL)
						{
                            printf("Memory allocation failed!\n");
                            exit(1);
                        }
                        scanEmployee(&(*employees)[*count]);
                        (*count)++;
                        break;
                    case 2:
                        for (int i = 0; i < *count; i++) 
						{
                            displayEmployee((*employees)[i]);
                        }
                        break;
                    case 3:
                        printf("Enter Employee ID to search: ");
                        scanf("%d", &id);
                        index = searchById(*employees, *count, id);
                        if (index != -1) 
						{
                            displayEmployee((*employees)[index]);
                        }
						else
						{
                            printf("Employee not found!\n");
                        }
                        break;
                    case 4:
                        printf("Enter Employee Last Name to search: ");
                        scanf("%s", lastName);
                        index = searchByLastName(*employees, *count, lastName);
                        if (index != -1)
						{
                            displayEmployee((*employees)[index]);
                        }
						else 
						{
                            printf("Employee not found!\n");
                        }
                        break;
                    case 5:
                        printf("Enter minimum salary: ");
                        scanf("%f", &minSalary);
                        printf("Enter maximum salary: ");
                        scanf("%f", &maxSalary);
                        searchBySalaryRange(*employees, *count, minSalary, maxSalary);
                        break;
                    case 6:
                        printf("Enter Employee ID to update: ");
                        scanf("%d", &id);
                        index = searchById(*employees, *count, id);
                        if (index != -1) {
                            printf("Enter new last name: ");
                            scanf("%s", lastName);
                            updateLastName(&(*employees)[index], lastName);
                            printf("Employee last name updated successfully!\n");
                        }
						else
						{
                            printf("Employee not found!\n");
                        }
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
                break;
            case 2:
                printf("Enter minimum salary: ");
                scanf("%f", &minSalary);
                printf("Enter maximum salary: ");
                scanf("%f", &maxSalary);
                searchBySalaryRange(*employees, *count, minSalary, maxSalary);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to scan employee details
void scanEmployee(struct Employee *employee)
{
    printf("Enter Employee ID: ");
    scanf("%d", &employee->id);
    printf("Enter First Name: ");
    scanf("%s", employee->firstName);
    printf("Enter Last Name: ");
    scanf("%s", employee->lastName);
    printf("Enter Title: ");
    scanf("%s", employee->title);
    printf("Enter Salary: ");
    scanf("%f", &employee->salary);
}

// Function to display employee details
void displayEmployee(struct Employee employee)
{
    printf("\nEmployee ID: %d\n", employee.id);
    printf("First Name: %s\n", employee.firstName);
    printf("Last Name: %s\n", employee.lastName);
    printf("Title: %s\n", employee.title);
    printf("Salary: %.2f\n", employee.salary);
}

// Function to search employee by ID
int searchById(struct Employee *employees, int count, int id)
{
    for (int i = 0; i < count; i++)
	{
        if (employees[i].id == id) 
		{
            return i;
        }
    }
    return -1; // Not found
}

// Function to search employee by last name
int searchByLastName(struct Employee *employees, int count, char *lastName)
{
    for (int i = 0; i < count; i++)
	{
        if (strcmp(employees[i].lastName, lastName) == 0)
		{
            return i;
        }
    }
    return -1; // Not found
}

// Function to search employees by salary range
void searchBySalaryRange(struct Employee *employees, int count, float minSalary, float maxSalary)
{
    int found = 0;
    for (int i = 0; i < count; i++)
	{
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary)
		{
            displayEmployee(employees[i]);
            found = 1;
        }
    }
    if (!found)
	{
        printf("No employees found in the given salary range.\n");
    }
}

// Function to update employee last name
void updateLastName(struct Employee *employee, char *lastName) 
{
    strcpy(employee->lastName, lastName);
}

