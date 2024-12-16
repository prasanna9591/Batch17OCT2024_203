// gslist_util.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gslist_util.h"

int is_user_exist(const char *username) {
    FILE *file = fopen("registered_users.txt", "r");
    if (!file) {
        perror("Unable to open registration file");
        return -1;
    }

    char stored_username[128];
    while (fscanf(file, "%s", stored_username) != EOF) {
        if (strcmp(stored_username, username) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

