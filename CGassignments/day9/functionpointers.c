Function Pointers-

1. WAP to invoke functions below based on user input character using function pointer. Character mapping and respective functions to be invoked are given below.

Character input Function

+ int add(int x, int y)

- int sub(int x, int y)

* int multiply(int x, int y)

/ int divide(int x, int y)

#include <stdio.h>

/******************************************************************************
*
*       Function Name   : int add(int x, int y), int sub(int x, int y), int multiply(int x, int y),int divide(int x, int y)
*       Description     : performs arithemetic operation of two integers x and y
*       Returns         : int
*
*******************************************************************************/

// Function prototypes
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() {
    char operator;
    int x, y, result;

    // Ask for user input
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Use " %c" to avoid newline character issues

    // Ask for integer inputs
    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);

    // Declare a function pointer
    int (*operation)(int, int);

    // Assign the correct function pointer based on user input
    switch (operator) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = sub;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            operation = divide;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;  // Exit if invalid operator
    }

    // Invoke the function using the pointer
    result = operation(x, y);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}

// Function implementations
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}


_____________________________________________________________________________________________________________________________________________________________________________
2. Extend Q1 to include a function below which will return the address of a function based on input character.

<address of function> getaddr(char mychar);

#include <stdio.h>

// Function prototypes
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

// Function to return the address of a function based on input character
int (*getaddr(char mychar))(int, int);

int main() {
    char operator;
    int x, y, result;

    // Ask for user input
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Use " %c" to avoid newline character issues

    // Ask for integer inputs
    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);

    // Get the function address using getaddr() based on user input
    int (*operation)(int, int) = getaddr(operator);

    if (operation != NULL) {
        // Invoke the function using the pointer
        result = operation(x, y);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operator.\n");
    }

    return 0;
}

// Function implementations
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

// Function to return the address of a function based on input character
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+': return add;
        case '-': return sub;
        case '*': return multiply;
        case '/': return divide;
        default: return NULL;
    }
}





__________________________________________________________________________________________________________________________________________________________________________________
3. Extend Q1 to include a function below which takes a function pointer to a calculator function and one integer (value = 10) as arguments and shall invoke the given function 
with required arguments. For the second argument read input from user. Return the result.
int invokefunc(<function pointer as argument1>, int val1);

#include <stdio.h>

// Function prototypes
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int invokefunc(int (*func_ptr)(int, int), int val1);

int main() {
    char operator;
    int x, y, result;

    // Ask for user input
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Ask for second operand input
    printf("Enter second operand: ");
    scanf("%d", &y);

    // Get the function pointer using operator input
    int (*operation)(int, int) = getaddr(operator);

    if (operation != NULL) {
        // Invoke invokefunc with the fixed value 10
        result = invokefunc(operation, 10);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operator.\n");
    }

    return 0;
}

// Function implementations
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

// Function to return the address of a function based on input character
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+': return add;
        case '-': return sub;
        case '*': return multiply;
        case '/': return divide;
        default: return NULL;
    }
}

// Function to invoke the passed function with fixed value 10
int invokefunc(int (*func_ptr)(int, int), int val1) {
    int val2;
    printf("Enter the second operand: ");
    scanf("%d", &val2);
    
    return func_ptr(val1, val2);  // Invoke function with val1 (fixed value) and val2 (user input)
}



_________________________________________________________________________________________________________________________________________________________________________________

4. Extend Q1 to define an array of function pointers and invoke them based user input character.

#include <stdio.h>

// Function prototypes
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() {
    char operator;
    int x, y, result;

    // Array of function pointers
    int (*operations[4])(int, int) = {add, sub, multiply, divide};

    // Ask for user input
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Ask for integer inputs
    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);

    // Select the appropriate function based on operator input
    int operation_index;
    switch (operator) {
        case '+':
            operation_index = 0;
            break;
        case '-':
            operation_index = 1;
            break;
        case '*':
            operation_index = 2;
            break;
        case '/':
            operation_index = 3;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    // Invoke the function using the array of function pointers
    result = operations[operation_index](x, y);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}

// Function implementations
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}
