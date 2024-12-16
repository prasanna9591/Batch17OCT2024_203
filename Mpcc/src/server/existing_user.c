// existing_user.c
#include <stdio.h>
#include <string.h>
#include "client_authentication.h"

int authenticate_existing_user(const char *username, const char *password) {
    return authenticate_user(username, password);
}
