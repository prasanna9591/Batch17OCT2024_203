// existing_user_processing.c
#include <stdio.h>
#include <string.h>
#include "gslist_util.h"

#define IP_USER_FILE "ip_user_mapping.txt"

int map_ip_to_user(const char *ip, const char *username) {
    FILE *file = fopen(IP_USER_FILE, "a");
    if (!file) {
        perror("Unable to open IP mapping file");
        return -1;
    }

    fprintf(file, "%s %s\n", ip, username);
    fclose(file);
    return 0;
}

