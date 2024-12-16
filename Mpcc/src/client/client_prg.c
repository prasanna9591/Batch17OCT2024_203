// client_prg.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>



#define SERVER_ADDR "127.0.0.1"
#define PORT 8080

int sock;  // Global socket for sending and receiving messages

// Function for receiving messages from the server
void *receive_messages(void *arg) {
    char buffer[1024];
    int bytes_received;
    
    while (1) {
        bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Server disconnected\n");
            } else {
                perror("recv failed");
            }
            break;
        }

        buffer[bytes_received] = '\0';  // Null-terminate the received message
        printf("Received: %s\n", buffer);  // Print received message
    }
    
    return NULL;
}

// Function for sending messages to the server
void *send_messages(void *arg) {
    char message[1024];

    while (1) {
        // Get message from user
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character
        
        if (send(sock, message, strlen(message), 0) == -1) {
            perror("send failed");
            break;
        }
    }

    return NULL;
}

int main() {
    struct sockaddr_in server_addr;

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server at %s:%d\n", SERVER_ADDR, PORT);

    // Create threads for sending and receiving messages
    pthread_t recv_thread, send_thread;

    // Create a thread for receiving messages
    if (pthread_create(&recv_thread, NULL, receive_messages, NULL) != 0) {
        perror("Thread creation failed for receiving messages");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Create a thread for sending messages
    if (pthread_create(&send_thread, NULL, send_messages, NULL) != 0) {
        perror("Thread creation failed for sending messages");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    pthread_join(recv_thread, NULL);
    pthread_join(send_thread, NULL);

    // Close the socket when done
    close(sock);
    return 0;
}
