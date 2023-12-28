#include "programHandler.h"
#include "/home/logan/Desktop/git/PM2-Replacement/dataTrail/outputLogger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LENGTH 256

void testFunction() {
        printf("Test Function\n");
}

void inputFormat(char *program) {
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

void startProgram() {
	char programHolder[MAX_LENGTH];
        char *program;
        printf("Enter Program Name to Start: ");
        if (fgets(programHolder, sizeof(programHolder), stdin) != NULL) {
                        // Remove the newline character from the input
                if (programHolder[strlen(programHolder) - 1] == '\n') {
                        programHolder[strlen(programHolder) - 1] = '\0';
                }
        }

        program = strdup(programHolder);

	pid_t pid = fork();
        
	if (pid < 0) {
                printf("Fork Failed.\n");
        } else if (pid == 0) {
        	inputFormat(program);
		
        } else {
        	exit(0);
        }
	free(program);
}



