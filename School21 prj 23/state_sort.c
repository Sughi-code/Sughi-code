#include "state_sort.h"

int main() {
    int choice = 0;
    FILE* file = NULL;

    file_name(file);

    while (choice != -1) {
        while (getchar() != '\n');
        if (scanf("%d", &choice) != 1) {
            printf("n/a\n");
            continue;
        }

        switch (choice) {
            case 0:
                print_file(file);
                break;
            case 1:
                sort_file(file);
                break;
            case 2:
                write_file(file);
                break;
            default: {
                printf("n/a\n");
            }
        }
    }

    if (file) fclose(file);
    return 0;
}
int compare_records(const void* a, const void* b) {
    const Record* r1 = a;
    const Record* r2 = b;
    if (r1->year != r2->year) return r1->year - r2->year;
    if (r1->month != r2->month) return r1->month - r2->month;
    return r1->day - r2->day;
}
void file_name(const FILE* file) {
    int flag = 1;
    char filename[100];
    while (flag) {
        scanf("%99s", filename);
        file = fopen(filename, "rb+");
        if (!file) {
            printf("n/a\n");
            continue;
        }
        flag = 0;
    }
}
void print_file(FILE* file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    int total_records = file_size / sizeof(Record);

    Record* buffer = malloc(total_records * sizeof(Record));
    if (!buffer) {
        printf("n/a\n");
        return;
    }

    fread(buffer, sizeof(Record), total_records, file);
    for (int i = 0; i < total_records; i++) {
        printf("%d %d %d %d %d %d %d %d%s", buffer[i].year, buffer[i].month, buffer[i].day, buffer[i].hour,
               buffer[i].minute, buffer[i].second, buffer[i].status, buffer[i].code,
               (i == total_records - 1) ? "" : "\n");
    }

    free(buffer);
}

void sort_file(FILE* file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    int total_records = file_size / sizeof(Record);

    Record* buffer = malloc(total_records * sizeof(Record));
    if (!buffer) {
        printf("n/a\n");
        return;
    }

    fread(buffer, sizeof(Record), total_records, file);
    qsort(buffer, total_records, sizeof(Record), compare_records);

    for (int i = 0; i < total_records; i++) {
        printf("%d %d %d %d %d %d %d %d%s", buffer[i].year, buffer[i].month, buffer[i].day, buffer[i].hour,
               buffer[i].minute, buffer[i].second, buffer[i].status, buffer[i].code,
               (i == total_records - 1) ? "" : "\n");
    }

    free(buffer);
}

void write_file(FILE* file) {
    char text[100] = {'\0'};
    scanf("%99s", text);
    fprintf(file, "\n%s", text);
    print_file(file);
}