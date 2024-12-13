// client_handler.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "broadcast_handler.c"
//#include "active_session.c"
#include "log_server_report.h"

void *handle_client(void *arg) {
	int socket =*(int*)arg;
    char buffer[1024];
    int bytes_received;

    // Read the client's message
    while ((bytes_received = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        broadcast_message(buffer, socket);
    }

    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else if (bytes_received == -1) {
        perror("Recv failed");
    }
	return NULL;
}

