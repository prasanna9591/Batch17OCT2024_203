// server_prg.h
#ifndef SERVER_PRG_H
#define SERVER_PRG_H

#define PORT 8080
#define MAX_CLIENTS 10

// Function prototypes for server-side functionalities
void *handle_client(void *arg);
int main();

#endif // SERVER_PRG_H

