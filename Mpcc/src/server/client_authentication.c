#include <stdio.h>
#include <string.h>
#include "common_crypto.h"

#define REGISTER_FILE "registered_users.txt"

int authenticate_user(const char *username, const char *password) {
    FILE *file = fopen(REGISTER_FILE, "r");
    if (!file) {
        perror("Unable to open registration file");
        return -1;
    }

    char stored_username[128], stored_password[128];
    char encrypted_password[128];
    encrypt(password, encrypted_password);

    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(stored_username, username) == 0 && strcmp(stored_password, encrypted_password) == 0) {
            fclose(file);
            return 1;  // Authentication successful
        }
    }

    fclose(file);
    return 0;  // Authentication failed
}

