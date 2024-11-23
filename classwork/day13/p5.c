#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

typedef struct 
{
    int id;
    char name[50];
    char gender;
    int phone;
    float salary;
} EMP;


EMP* readEmployees(const char *filename, int *count);
void printEmployees(const EMP *employees, int count);

int main() 
{
    int count = 0;
    EMP *employees = readEmployees("Db.txt", &count);

    if (employees != NULL)
	{
        printEmployees(employees, count);
        free(employees);
    }

    return 0;
}


EMP* readEmployees(const char *filename, int *count) 
{
    FILE *file;
    EMP *employees = NULL;
    char line[MAX_LINE_LENGTH];
    int capacity = 10; 

    employees = (EMP *)malloc(capacity * sizeof(EMP));
    if (employees == NULL) 
	{
        perror("malloc: ");
		exit(1);
    }

  
    file = fopen(filename, "r");
    if (file == NULL) 
	{
        perror("fopen: ");
        free(employees);
        exit(1);
    }

      while (fgets(line, sizeof(line), file)) 
	{
        if (*count >= capacity) 
		{
            capacity *= 2;
            employees = (EMP *)realloc(employees, capacity * sizeof(EMP));
            if (employees == NULL) 
			{
                perror("realloc: ");
                fclose(file);
                exit(1);
            }
        }
        sscanf(line, "%d|%[^|]|%c|%d|%f", &employees[*count].id, employees[*count].name, &employees[*count].gender, &employees[*count].phone, &employees[*count].salary);
        (*count)++;
    }

    fclose(file);

    return employees;
}

void printEmployees(const EMP *employees, int count) 
{
    printf("Employee Records:\n");
    for (int i = 0; i < count; i++) 
	{
        printf("%d|%s|%c|%d|%.0f\n", employees[i].id, employees[i].name, employees[i].gender, employees[i].phone, employees[i].salary);
    }
}

