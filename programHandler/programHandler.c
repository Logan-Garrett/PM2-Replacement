#include "programHandler.h"
#include "/home/logan/Desktop/git/PM2-Replacement/dataTrail/outputLogger.h"

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
	int errorCheck;

        if (strstr(program, "./") != NULL) {
		errorCheck = system(program);
        } else {
                sprintf(command, "./%s", program);
                errorCheck = system(command);
        }
	
	if (errorCheck != 0) {
		errorLogger(command);
	}
}

