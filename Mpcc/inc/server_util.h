// server_util.h
#ifndef SERVER_UTIL_H
#define SERVER_UTIL_H

#include <stdio.h>
#include <stdlib.h>

// Function prototypes for managing active sessions and logging
void add_session(int socket, const char *username);
void remove_session(int socket);
int is_session_active(int socket);
void log_server_report(const char *level, const char *message, ...);

#endif // SERVER_UTIL_H

