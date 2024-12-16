// brdcst_send_handler.c
#include <sys/socket.h>   // Add this to use the `send` function
#include <unistd.h>        // For close() function (if needed)#include <stdio.h>
#include <string.h>
#include <stdio.h>

void send_message(int sock, const char *message) {
    send(sock, message, strlen(message), 0);
    printf("Message Sent: %s\n", message);
}

