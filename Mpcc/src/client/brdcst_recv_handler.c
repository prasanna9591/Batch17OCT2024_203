// brdcst_recv_handler.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void handle_received_message(int sock) {
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }
}

