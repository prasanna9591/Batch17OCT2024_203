// client_util.h
#ifndef CLIENT_UTIL_H
#define CLIENT_UTIL_H

#include <stdio.h>

// Function prototypes for client-side functionalities
void get_login_details(char *username, char *password);
void send_message(int socket, const char *message);
int receive_message(int socket, char *buffer, size_t buffer_size);
void log_client_report(const char *level, const char *message, ...);

#endif // CLIENT_UTIL_H

