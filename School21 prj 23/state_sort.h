#ifndef STATE_SORT_H
#define STATE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year, month, day, hour, minute, second, status, code;
} Record;

void print_file(FILE* file);
void sort_file(FILE* file);
void write_file(FILE* file);
int compare_records(const void* a, const void* b);
void file_name( const FILE* file);

#endif