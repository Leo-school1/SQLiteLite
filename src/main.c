#include <stdio.h>
#include <stdlib.h>
#include "repl.h"

int main() {
    repl_init();

    repl_run();

    repl_cleanup();

    return 0;
}