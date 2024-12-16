// get_login_details.c
#include <stdio.h>

void get_login_details(char *username, char *password) {
    printf("Enter username: ");
    fgets(username, 128, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, 128, stdin);
    password[strcspn(password, "\n")] = '\0';
}
