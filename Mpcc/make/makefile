# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -pthread

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

# Files
SERVER_SRC = $(SRC_DIR)/server_prg.c $(SRC_DIR)/active_session.c $(SRC_DIR)/add_to_reg_user_file.c $(SRC_DIR)/broadcast_handler.c \
             $(SRC_DIR)/client_authentication.c $(SRC_DIR)/client_handler.c $(SRC_DIR)/existing_user_processing.c \
             $(SRC_DIR)/gslist_util.c $(SRC_DIR)/is_user_exist.c $(SRC_DIR)/log_server_report.c $(SRC_DIR)/new_user_processing.c \
             $(SRC_DIR)/send_recv.c $(SRC_DIR)/stub_driver.c

CLIENT_SRC = $(SRC_DIR)/client_prg.c $(SRC_DIR)/brdcst_recv_handler.c $(SRC_DIR)/brdcst_send_handler.c $(SRC_DIR)/client_send_recv.c \
             $(SRC_DIR)/existing_user.c $(SRC_DIR)/get_login_details.c $(SRC_DIR)/log_client_report.c $(SRC_DIR)/new_user.c \
             $(SRC_DIR)/stub_driver.c

# Headers
SERVER_INC = $(INC_DIR)/server_util.h $(INC_DIR)/common_crypto.h $(INC_DIR)/gslist_util.h $(INC_DIR)/log_server_report.h \
             $(INC_DIR)/active_session.h $(INC_DIR)/add_to_reg_user_file.h $(INC_DIR)/broadcast_handler.h \
             $(INC_DIR)/client_authentication.h $(INC_DIR)/send_recv.h

CLIENT_INC = $(INC_DIR)/client_util.h $(INC_DIR)/common_crypto.h $(INC_DIR)/gslist_util.h $(INC_DIR)/log_client_report.h \
             $(INC_DIR)/client_authentication.h $(INC_DIR)/send_recv.h

# Object files
SERVER_OBJ = $(OBJ_DIR)/server_prg.o $(OBJ_DIR)/active_session.o $(OBJ_DIR)/add_to_reg_user_file.o $(OBJ_DIR)/broadcast_handler.o \
             $(OBJ_DIR)/client_authentication.o $(OBJ_DIR)/client_handler.o $(OBJ_DIR)/existing_user_processing.o \
             $(OBJ_DIR)/gslist_util.o $(OBJ_DIR)/is_user_exist.o $(OBJ_DIR)/log_server_report.o $(OBJ_DIR)/new_user_processing.o \
             $(OBJ_DIR)/send_recv.o $(OBJ_DIR)/stub_driver.o

CLIENT_OBJ = $(OBJ_DIR)/client_prg.o $(OBJ_DIR)/brdcst_recv_handler.o $(OBJ_DIR)/brdcst_send_handler.o $(OBJ_DIR)/client_send_recv.o \
             $(OBJ_DIR)/existing_user.o $(OBJ_DIR)/get_login_details.o $(OBJ_DIR)/log_client_report.o $(OBJ_DIR)/new_user.o \
             $(OBJ_DIR)/stub_driver.o

# Final executables
SERVER_BIN = $(BIN_DIR)/server
CLIENT_BIN = $(BIN_DIR)/client

# Default target
all: $(SERVER_BIN) $(CLIENT_BIN)

# Server compilation rule
$(SERVER_BIN): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Client compilation rule
$(CLIENT_BIN): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile server .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SERVER_INC)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to compile client .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(CLIENT_INC)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean up object and binary files
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Rebuild everything (clean + all)
rebuild: clean all

.PHONY: all clean rebuild
