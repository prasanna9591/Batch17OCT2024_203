// broadcast_handler.c
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include "log_server_report.h"
#include "active_session.h"

extern pthread_mutex_t clients_mutex;
extern int clients[MAX_SESSIONS];

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (clients[i] != 0 && clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}
