// gslist_util.h
#ifndef GSLIST_UTIL_H
#define GSLIST_UTIL_H

#include <stdio.h>

// Function prototypes for user existence checks and IP mapping
int is_user_exist(const char *username);
int map_ip_to_user(const char *ip, const char *username);
int process_new_user(const char *username, const char *password);

#endif // GSLIST_UTIL_H

