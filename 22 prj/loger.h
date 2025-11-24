#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LOGER_H
#define LOGER_H
typedef enum { DEBUG, INFO, WARNING, ERROR } log_level;

FILE* log_init();
int logcat(FILE* log_file, const char* message, log_level level);
int log_close(FILE* log_file);
#endif