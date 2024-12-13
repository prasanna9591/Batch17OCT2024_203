// new_user_processing.c
#include <stdio.h>
#include <string.h>
#include "gslist_util.c"
#include "add_to_reg_user_file.c"

int process_new_user(const char *username, const char *password) {
    if (is_user_exist(username)) {
        printf("User already exists!\n");
        return 0;
    }

    if (add_to_reg_user_file(username, password) == 0) {
        printf("User registered successfully.\n");
        return 1;
    } else {
        printf("Registration failed.\n");
        return -1;
    }
}

