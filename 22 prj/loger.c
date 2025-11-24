#include "loger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Преобразование уровня в строку
const char* level_to_string(log_level level) {
    switch (level) {
        case (DEBUG):
            return "DEBUG";
        case (INFO):
            return "INFO";
        case (WARNING):
            return "WARNING";
        case (ERROR):
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

FILE* log_init() {
    FILE* file = fopen("log_file.txt", "a+");
    if (!file) {
        return NULL;
    }
    return file;
}

int logcat(FILE* log_file, const char* message, log_level level) {
    if (!log_file || !message) {
        return -1;
    }

    time_t now = time(NULL);
    const struct tm* t = localtime(&now);
    char time_str[80];
    strftime(time_str, sizeof(time_str) - 1, "%Y-%m-%d %H:%M:%S", t);

    const char* level_str = level_to_string(level);
    fprintf(log_file, "[%s] %s: %s\n", time_str, level_str, message);
    fflush(log_file);

    return 0;
}

int log_close(FILE* log_file) {
    if (!log_file) {
        return -1;
    }
    fclose(log_file);
    return 0;
}