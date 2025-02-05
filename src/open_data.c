#include<stdio.h>
#include "open_data.h"

#define MAX_NAME_SIZE 64
#define MAX_TABLES 32
struct TableMetadata {
    char table_name[MAX_NAME_SIZE];
    long table_position
};

struct DatabaseHeader {
    int table_count;
    struct TableMetadata tables[MAX_TABLES];
};

//finds new database or creates one 
void link_database(const char *file_name) {
    FILE *fptr = fopen(file_name, "rb");
    if (fptr != NULL) {
        fclose(fptr);
        printf("Database file linked successfully.\n");
        return;
    } else {
        new_database(file_name);
    }
    
}
void new_database(const char *file_name) {
    FILE *fptr = fopen(file_name, "wb");
    if (fptr == NULL) {
        printf("Error: Could not create database file.\n");
        return;
    }
    // initialize header
    struct DatabaseHeader header = {0};
    header.table_count = 0;
    for (int i = 0; i < MAX_TABLES; i++) {
        header.tables[i].table_name[0] = '\0';
        header.tables[i].table_position = 0;
    }
    
    fwrite(&header, sizeof(header), 1, fptr);

    fclose(fptr);
    printf("Database file created successfully.\n");
    return;
}