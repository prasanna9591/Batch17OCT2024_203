#include "active_session.h"
#include <string.h>
#include <stdio.h>

// Declare the mutex globally and initialize it
pthread_mutex_t session_mutex = PTHREAD_MUTEX_INITIALIZER;

// Declare the array of active sessions
ActiveSession active_sessions[MAX_SESSIONS] = {0}; // Initialize all sessions as inactive

// Function to add a session
void add_session(int socket, const char *username) {
    pthread_mutex_lock(&session_mutex);  // Locking for thread safety

    // Find an inactive session slot
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].active == 0) {  // Check for an inactive session
            active_sessions[i].socket = socket;  // Assign socket
            strncpy(active_sessions[i].username, username, sizeof(active_sessions[i].username) - 1);  // Copy username safely
            active_sessions[i].username[sizeof(active_sessions[i].username) - 1] = '\0';  // Ensure null termination
            active_sessions[i].active = 1;  // Mark the session as active
            printf("Session added: %s with socket %d\n", username, socket);
            break;
        }
    }

    pthread_mutex_unlock(&session_mutex);  // Unlocking
}

// Function to remove a session
void remove_session(int socket) {
    pthread_mutex_lock(&session_mutex);  // Locking for thread safety

    // Find the session with the given socket and mark it as inactive
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].socket == socket) {
            active_sessions[i].active = 0;  // Mark the session as inactive
            printf("Session removed: socket %d\n", socket);
            break;
        }
    }

    pthread_mutex_unlock(&session_mutex);  // Unlocking
}

// Function to check if a session is active
int is_session_active(int socket) {
    pthread_mutex_lock(&session_mutex);  // Locking for thread safety

    int session_found = 0;

    // Loop through all sessions to check if the given socket is active
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (active_sessions[i].socket == socket && active_sessions[i].active == 1) {
            session_found = 1;  // Session is active
            break;
        }
    }

    pthread_mutex_unlock(&session_mutex);  // Unlocking

    return session_found;  // Return 1 if the session is active, 0 if not
}

