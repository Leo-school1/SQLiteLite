#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"

#define BUFFER_SIZE 1024

void repl_init() {
    printf("Welcome to SQLiteLite!\n");
    printf("Type 'exit' to quit.\n");
}

void repl_run() {
    char input[BUFFER_SIZE];

    while (true) {
        printf("> ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            break; // Handle EOF
        }

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Evaluate the command (placeholder for actual evaluation logic)
        printf("You entered: %s\n", input);
    }
}

void repl_cleanup() {
    printf("Exiting Database. Goodbye!\n");
}