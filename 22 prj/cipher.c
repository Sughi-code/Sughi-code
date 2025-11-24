#include "cipher.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loger.h"

void read_file(const char* filename, FILE* log_file) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        logcat(log_file, "Try to read false file", ERROR);
        printf("n/a");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size == 0) {
        fclose(file);
        logcat(log_file, "Try to read empty file", ERROR);
        printf("n/a");
        return;
    }

    char* buffer = malloc(size + 1);
    if (!buffer) {
        fclose(file);
        logcat(log_file, "False of malloc for massage", ERROR);
        printf("n/a");
        return;
    }

    if (fread(buffer, sizeof(char), size, file) != (size_t)size) {
        free(buffer);
        fclose(file);
        logcat(log_file, "Uncorrect field in file", ERROR);
        printf("n/a");
        return;
    }

    buffer[size] = '\0';
    printf("%s", buffer);

    free(buffer);
    fclose(file);
}

void write_file(const char* filename, FILE* log_file) {  // text wroten in file is - '/n' in several tymes
    FILE* file = fopen(filename, "a+");
    if (!file) {
        logcat(log_file, "Try to write massage into false file", ERROR);
        printf("n/a");
        return;
    }
    char text[100] = {'\0'};
    scanf("%99s", text);
    char massage[140] = "Message has writen in file- ";
    strcat(massage, filename);
    logcat(log_file, massage, INFO);
    fprintf(file, "%s\n", text);
    fclose(file);

    read_file(filename, log_file);
}
// If function
int file_exists(const char* filename, FILE* log_file) {
    FILE* file = fopen(filename, "r");
    if (file) {
        logcat(log_file, "Checking if file exist", DEBUG);
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    FILE* log_file = log_init();
    if (!log_file) {
        printf("Ошибка инициализации лог-файла\n");
        return -1;
    }
    logcat(log_file, "Программа запущена", INFO);

    int choice = 0;
    char filename[100] = {'\0'};
    while (choice != -1) {
        if (scanf(" %d", &choice) != 1) {
            logcat(log_file, "Uncorrect choice of comand", ERROR);
            printf("n/a\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == -1) {
            logcat(log_file, "Выход из программы", INFO);
            break;
        }

        if (choice == 1) {
            if (scanf("%99s", filename) != 1) {
                logcat(log_file, "Uncorrect input filename", ERROR);
                printf("n/a\n");
                continue;
            }
            read_file(filename, log_file);
            printf("\n");
        } else if (choice == 2) {
            if (!file_exists(filename, log_file)) {
                logcat(log_file, "Try to write text without input file", WARNING);
                printf("n/a\n");
                continue;
            }
            write_file(filename, log_file);
            printf("\n");
        } else {
            logcat(log_file, "False comand input", DEBUG);
            printf("n/a\n");
        }
    }
    if (log_close(log_file) == -1) {
        printf("failed to close log_file.txt\n");
    }

    return 0;
}