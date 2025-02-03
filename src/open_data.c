#include<stdio.h>
#include "open_data.h"


// links OR creates database file
void link_database(const char *file_name) {
    FILE *fptr = fopen(file_name, "rb");
    if (fptr != NULL) {
        fclose(fptr);
        printf("Database file linked successfully.\n");
        return;

    }
    fptr = fopen(file_name, "wb");
    if (fptr == NULL) {
        printf("Error: Could not create database file.\n");
        return;
    }
    printf("Database file created successfully.\n");
    fclose(fptr);
    return;
}