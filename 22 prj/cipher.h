#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CIPHER_H
#define CIPHER_H
void read_file(const char* filename, FILE* log_file);
void write_file(const char* filename, FILE* log_file);
int file_exists(const char* filename, FILE* log_file);
#endif