// log_client_report.c
#include <stdio.h>
#include <stdarg.h>

#define LOG_FILE "client_log.txt"

void log_client_report(const char *level, const char *message, ...) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Unable to open log file");
        return;
    }

    va_list args;
    va_start(args, message);
    fprintf(log_file, "[%s] ", level);
    vfprintf(log_file, message, args);
    fprintf(log_file, "\n");
    va_end(args);

    fclose(log_file);
}

