// active_session.h
#ifndef ACTIVE_SESSION_H
#define ACTIVE_SESSION_H

#define MAX_SESSIONS 100

// Structure to store session information
typedef struct {
    int socket;
    char username[128];
	int active;

} Session;
extern Session active_sessions[MAX_SESSIONS];
extern pthread_mutex_t session_mutex;

// Function prototypes for managing active sessions
//void add_session(int socket, const char *username);
//void remove_session(int socket);
//int is_session_active(int socket);

#endif // ACTIVE_SESSION_H

