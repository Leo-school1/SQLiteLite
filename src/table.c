#include<stdio.h>
#include "table.h"
#include "open_data.h"

void table_init(const char *table_name, const char *file_name) {
    FILE *fptr = fopen(file_name, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open database file.\n");
        return;
    }
    
    struct DatabaseHeader header;
    fread(&header, sizeof(header), 1, fptr);

    if (header.table_count >= MAX_TABLES) {
        printf("Error: Maximum number of tables reached.\n");
        fclose(fptr);
        return;
    }
    if (table_exists(table_name, file_name) == 1) {
        fclose(fptr);
        return;
    }
    
    for (int i = 0; i < MAX_TABLES; i++) {
        if (header.tables[i].table_name[0] == '\0') {
            strcpy(header.tables[i].table_name, table_name);
            header.table_count++;
            break;
        }
    }


}

// returns 1 if table exists, 0 if it doesn't
int table_exists(const char *table_name, const char *file_name) {
    FILE *fptr = fopen(file_name, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }
    
    struct DatabaseHeader header;
    fread(&header, sizeof(header), 1, fptr);

    for (int i = 0; i < header.table_count; i++) {
        if (strcmp(header.tables[i].table_name, table_name) == 0) {
            printf("Error: Table already exists.\n");
            fclose(fptr);
            return 1;
        }
    }
    fclose(fptr);
    return 0;
}

void print_table(const char *tablename, const char *filename) {
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open database file.\n");
        return;
    }
    
    struct DatabaseHeader header;
    fread(&header, sizeof(header), 1, fptr);

    for (int i = 0; i < header.table_count; i++) {
        if (strcmp(header.tables[i].table_name, tablename) == 0) {
            
            fclose(fptr);
            return;
        }
    }
    printf("Error: Table not found.\n");
    fclose(fptr);
    return;
}