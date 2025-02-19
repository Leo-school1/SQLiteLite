#ifndef OPEN_DATA_H
#define OPEN_DATA_H

#define MAX_NAME_SIZE 64
#define MAX_TABLES 16
struct TableMetadata {
    char table_name[MAX_NAME_SIZE];
    long table_position;
};

struct DatabaseHeader {
    int table_count;
    struct TableMetadata tables[MAX_TABLES];
};

void link_database(const char *file_name);
void new_database(const char *file_name);

#endif 