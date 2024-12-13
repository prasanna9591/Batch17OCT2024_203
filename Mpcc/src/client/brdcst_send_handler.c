// brdcst_send_handler.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void send_message(int sock, const char *message) {
    send(sock, message, strlen(message), 0);
    printf("Message Sent: %s\n", message);
}

