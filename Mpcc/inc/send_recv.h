// send_recv.h
#ifndef SEND_RECV_H
#define SEND_RECV_H

// Function prototypes for sending and receiving messages
int send_message(int socket, const char *message);
int receive_message(int socket, char *buffer, size_t buffer_size);

#endif // SEND_RECV_H

