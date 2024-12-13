// new_user.c
#include <stdio.h>
#include <string.h>
#include "new_user_processing.c"

int register_new_user(const char *username, const char *password) {
    return process_new_user(username, password);
}

