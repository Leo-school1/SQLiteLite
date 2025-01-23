#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"
#include "table.h"

#define BUFFER_SIZE 1024

void repl_init() {
    printf("Welcome to SQLiteLite!\n");
    printf("Type '.exit' to quit.\n");
}

void repl_run() {
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
        
        
    }
}

void repl_cleanup() {
    printf("Exiting Database. Goodbye!\n");
}