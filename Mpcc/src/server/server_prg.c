// server_prg.c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "client_handler.c"
#include "log_server_report.c"
#include "config.h"
#define PORT 8080
#define MAX_CLIENTS 10

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
int clients[MAX_CLIENTS];

/*void *handle_client(void *arg) {
    int socket = *(int *)arg;
    free(arg);
    handle_client(socket);
    close(socket);
    return NULL;
}*/

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }
		pthread_t tid;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Thread creation failed");
        }
    }

    close(server_fd);
    return 0;
}

