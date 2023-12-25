#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

// File Type Controllers
#include "cHandler/cHandler.h"

int main(int argc, char *argv[]) {
	printf("Welcome to Task Master.\n");

	char *action = argv[1];
	// printf("Action being performed: %s\n", action);

	char *program = argv[2];
	// printf("Program being run: %s\n", program);

	if (argv[1] != NULL && argv[2] != NULL) {
		// Issue maybe arises in which program un-compiled. Work on maybe?
		if ((strcmp(action, "start") != 1) && (program != NULL)) {
			char command[100];
			pid_t pid = fork();
			if (pid < 0) {
				printf("Fork Failed.\n");
			} else if (pid == 0) {
				if (strstr(program, "./") != NULL) {
					system(program);
				} else {
					sprintf(command, "./%s", program);
					system(command);
				}
			} else {
				exit(0);
			}
		} else if(strcmp(action, "stop") == 0) {
			printf("Self-destruct sequence initiated...\n");
			system("sudo pkill test");
		} 

	} else {
		printf("How did you even get here?\n");
		testFunction();
	}

	return 0;
}
