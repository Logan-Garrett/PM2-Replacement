#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

// File Type Controllers
#include "programHandler/programHandler.h"

int main(int argc, char *argv[]) {
	// printf("Welcome to Task Master.\n");

	char *action = argv[1];
	// printf("Action being performed: %s\n", action);

	char *program = argv[2];
	// printf("Program being run: %s\n", program);

	if (argv[1] != NULL && argv[2] != NULL) {
		// Issue maybe arises in which program un-compiled. Work on maybe?
		if (strcmp(action, "start") == 0 && program != NULL) {
			pid_t pid = fork();
			if (pid < 0) {
				printf("Fork Failed.\n");
			} else if (pid == 0) {
				startProgram(program);
			} else {
				exit(0);
			}
		} else if(strcmp(action, "stop") == 0) {
			printf("Self-destruct sequence initiated...\n");
			system("sudo pkill test");
		} else {
			// Run normal commands?
			system(program);
		}
	} else if (argv[1] != NULL) { 
		if (strcmp(action, "--version") == 0 || strcmp(action, "version") == 0) {
			// int version;
			printf("Version: (Read From Some File)\n");
		} else if (strcmp(action, "dev-menu") == 0) {
			printf("You have entered Dev Menu.\n");
			printf("Here are some options.\n");
			testFunction();
		} else if (strcmp(action, "--help") == 0 || strcmp(action, "help") == 0) { 
			printf("--help requested info down below.\n");
		} else {
			// Not certain
		}
	} else {
		printf("That does not seem to be an option.\n");
		printf("If you need help try --help\n");
	}

	return 0;
}
