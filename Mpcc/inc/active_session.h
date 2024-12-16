#ifndef ACTIVE_SESSION_H
#define ACTIVE_SESSION_H

#include <pthread.h>

#define MAX_SESSIONS 100

typedef struct {
    int socket;
    char username[128];
    int active;
} ActiveSession;

extern ActiveSession active_sessions[MAX_SESSIONS];
extern pthread_mutex_t session_mutex;

void add_session(int socket, const char *username);
void remove_session(int socket);
int is_session_active(int socket);

#endif // ACTIVE_SESSION_H

