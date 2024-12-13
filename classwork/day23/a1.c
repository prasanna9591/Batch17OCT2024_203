#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void display_menu();
void handle_sigint(int sig);

int main() {
    signal(SIGINT, handle_sigint);
    int choice;
    float radius, length, width, base, height;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter radius of the circle: ");
                scanf("%f", &radius);
                printf("Area of the circle: %.2f\n", 3.14159 * radius * radius);
                break;
            case 2:
                printf("Enter length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                printf("Area of the rectangle: %.2f\n", length * width);
                break;
            case 3:
                printf("Enter base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("Area of the triangle: %.2f\n", 0.5 * base * height);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- Area Calculation Menu ---\n");
    printf("1. Area of Circle\n");
    printf("2. Area of Rectangle\n");
    printf("3. Area of Triangle\n");
    printf("0. Exit\n");
}

void handle_sigint(int sig) {
    printf("\nCaught signal %d (Ctrl+C). Redisplaying menu...\n", sig);
    display_menu();
}

