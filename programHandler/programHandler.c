#include "programHandler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

void testFunction() {
        printf("Test Function\n");
}

/* Add Function to check for JS or other lang */

void startProgram(char *program) {
        char command[100];

        if (strstr(program, "./") != NULL) {
                system(program);
        } else {
                sprintf(command, "./%s", program);
                system(command);
        }
}

