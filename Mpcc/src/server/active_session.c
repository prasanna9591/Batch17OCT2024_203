// active_session.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "log_server_report.h"
#include "active_session.h"
#include "config.h"
#define MAX_SESSIONS 100



void add_session(int socket, const char *username) {
    pthread_mutex_lock(&session_mutex);

    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].active == 0) {
            active_sessions[i].socket = socket;
            strncpy(active_sessions[i].username, username, 128);
            active_sessions[i].active = 1;
            break;
        }
    }

    pthread_mutex_unlock(&session_mutex);
}

void remove_session(int socket) {
    pthread_mutex_lock(&session_mutex);

    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].socket == socket) {
            active_sessions[i].active = 0;
            break;
        }
    }

    pthread_mutex_unlock(&session_mutex);
}

int is_session_active(int socket) {
    pthread_mutex_lock(&session_mutex);
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].socket == socket && active_sessions[i].active) {
            pthread_mutex_unlock(&session_mutex);
            return 1;
        }
    }
    pthread_mutex_unlock(&session_mutex);
    return 0;
}

