#include<stdio.h>
#include "open_data.h"


// links OR creates database file
char link_database(const char *file_name) {
    FILE *fptr = fopen(file_name, "rb");
    if (fptr != NULL) {
        return file_name;
        fclose(fptr);
    }
    fptr = fopen(file_name, "wb");
    if (fptr == NULL) {
        printf("Error: Could not create database file.\n");
        return NULL;
    }
    return file_name;
    fclose(fptr);
}