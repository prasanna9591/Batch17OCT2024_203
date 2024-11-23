CC = gcc

CFLAGS = -Wall -g

OBJDIR = obj

BINDIR = bin

SRCDIR = src
 
# List of source files

SRCS = $(SRCDIR)/employee.c $(SRCDIR)/file_operations.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
 
# Output binary file

TARGET = $(BINDIR)/employee_program
 
# Default target to build the project

all: $(TARGET)
 
# Create the target executable

$(TARGET): $(OBJS)

	$(CC) $(OBJS) -o $(TARGET)
 
# Create object files from source files

$(OBJDIR)/%.o: $(SRCDIR)/%.c

	$(CC) $(CFLAGS) -c $< -o $@
 
# Clean up object and binary files

clean:

	rm -rf $(OBJDIR)/*.o $(TARGET)

 
