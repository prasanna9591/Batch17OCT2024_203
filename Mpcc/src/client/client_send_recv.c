#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int send_message(int socket, const char *message) {
    return send(socket, message, strlen(message), 0);
}

int receive_message(int socket, char *buffer, size_t buffer_size) {
    return recv(socket, buffer, buffer_size, 0);
}

