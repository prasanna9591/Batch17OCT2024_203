# Compiler to use
CC = gcc

# Compiler flags (optional)
CFLAGS = -Wall -g -I ./inc   # Add -pthread here for thread-safe compilation

# Common source files (if any) that both client and server share
COMMON_SRC = $(wildcard src/common/*.c)

# Server-specific source files
SERVER_SRC = $(wildcard src/server/*.c)

# Client-specific source files
CLIENT_SRC = $(wildcard src/client/*.c)

# Combine common source files with server/client specific ones
SERVER_OBJ = $(COMMON_SRC:.c=.o) $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(COMMON_SRC:.c=.o) $(CLIENT_SRC:.c=.o)

# Output executable names
SERVER_EXEC = server_app
CLIENT_EXEC = client_app

# Default target: build both client and server
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Link object files to create the server executable
$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) -o $(SERVER_EXEC)   # Add -pthread during linking for the server

# Link object files to create the client executable
$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o $(CLIENT_EXEC)

# Compile the .c files into .o files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

# Clean up object files and the executables
clean:
	rm -f src/**/*.o $(SERVER_EXEC) $(CLIENT_EXEC)

# Rebuild everything from scratch
rebuild: clean all

