// client_send_recv.c
#include <stdio.h>
#include <string.h>

int send_message(int sock, const char *message) {
    return send(sock, message, strlen(message), 0);
}

int receive_message(int sock, char *buffer, size_t buffer_size) {
    return recv(sock, buffer, buffer_size, 0);
}

