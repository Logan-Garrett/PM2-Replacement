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

	if (argv[1] != NULL) {
		// Issue maybe arises in which program un-compiled. Work on maybe?
		if (strcmp(action, "start") == 0) {
			startProgram();
		} else if (strcmp(action, "stop") == 0) {
			char *pName = programName();
			int pid = currentProcess(pName);
			stopProgram(pid);
		} else if (strcmp(action, "status") == 0) {
		       	char *pName = programName();
	       		int pid = currentProcess(pName);
		 	statusOfProgram(pid);	
		} else if (strcmp(action, "--version") == 0 || strcmp(action, "version") == 0) {
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
			system(action);
		}
	} else {
		printf("That does not seem to be an option.\n");
		printf("If you need help try --help\n");
	}

	return 0;
}
