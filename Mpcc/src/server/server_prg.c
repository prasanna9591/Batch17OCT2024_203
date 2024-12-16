#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>  // Ensure pthread.h is included for thread functions
#include "client_handler.h"   // Make sure this file contains the correct declaration of handle_client
#include "log_server_report.h" // Your logging functionality

#define PORT 8080
#define MAX_CLIENTS 10

// Declare the mutex to synchronize client access
pthread_mutex_t clients_mutex = _PTHREAD_MUTEX_INIIALIZER;
int clients[MAX_CLIENTS]; // To hold active client sockets

// Handle client function prototype (ensure this function is defined correctly in client_handler.c)
void *handle_client(void *arg);  // Function prototype for handle_client

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept and handle client connections
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_t tid;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        // Create a thread to handle each client
        if (pthread_create(&tid, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Thread creation failed");
            free(new_sock);
        }
    }

    close(server_fd); // Close the server socket when done
    return 0;
}

