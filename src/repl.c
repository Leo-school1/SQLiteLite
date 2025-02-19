#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"
#include "table.h"
#include "open_data.h"
#define BUFFER_SIZE 1024

void repl_init() {
    printf("Welcome to SQLiteLite!\n");
    printf("Type '.exit' to quit.\n");
    printf("Type 'open FILENAME' to open or create a database file.\n");
}

void repl_run() {
    char file_name[BUFFER_SIZE] = {0};

    char input[BUFFER_SIZE];

    while (true) {
        printf("> ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            // End of file reached
            printf("Error Occurred!\n");
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");

        char *tokens_list[BUFFER_SIZE];

        int i = 0;
        while (token != NULL) {
            tokens_list[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        tokens_list[i] = token; // tokens_list is now a list of all commands separated by spaces

        if (strcmp(tokens_list[0], ".exit") == 0) {
            break;
        }
        if (strcmp(tokens_list[0], "open") == 0) {
            if (tokens_list[1] == NULL) {
                printf("Error: Must provide a filename.\n");
                continue;
            }
            strcpy(file_name, tokens_list[1]);
            link_database(file_name);
            continue;
        }
        if (strcmp(tokens_list[0], "new") == 0) {
            if (tokens_list[1] == NULL) {
                continue;
            }
            if (strcmp(tokens_list[1], "table") == 0) {
                if (file_name[0] == 0) {
                    printf("Error: No database file linked.\n");
                    continue;
                }
                if (tokens_list[2] == NULL) {
                    printf("Error: Must provide a table name.\n");
                    continue;
                }
                table_init(tokens_list[2], file_name);
                continue;
            }
        }
        if (strcmp(tokens_list[0], "get") == 0) {
            if (tokens_list[1] == "table") {
                if (file_name[0] == 0) {
                    printf("Error: No database file linked.\n");
                    continue;
                }
                if (tokens_list[2] == NULL) {
                    printf("Error: Must provide a key.\n");
                    continue;
                }
    
                print_table(tokens_list[2], file_name);
                continue;
            }
            
        }
        
    }
}

void repl_cleanup() {
    printf("Exiting Database. Goodbye!\n");
}