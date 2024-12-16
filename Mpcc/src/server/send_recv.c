// send_recv.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>   // For htons, inet_addr, sockaddr_in#include <sys/socket.h>  // For socket-related functions
int send_message(int socket, const char *message) {
    return send(socket, message, strlen(message), 0);
}

int receive_message(int socket, char *buffer, size_t buffer_size) {
    return recv(socket, buffer, buffer_size, 0);
}

