// add_to_reg_user_file.c
#include <stdio.h>
#include <string.h>
#include "common_crypto.h"

#define REGISTER_FILE "registered_users.txt"

int add_to_reg_user_file(const char *username, const char *password) {
    FILE *file = fopen(REGISTER_FILE, "a");
    if (!file) {
        perror("Unable to open registration file");
        return -1;
    }

    char encrypted_password[128];
    encrypt(password, encrypted_password);
    fprintf(file, "%s %s\n", username, encrypted_password);

    fclose(file);
    return 0;
}

