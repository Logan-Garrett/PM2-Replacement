#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("Welcome to Task Master.\n");

	char *action = argv[1];
	printf("Action being performed: %s\n", action);

	char *program = argv[2];
	printf("Program being run: %s\n", program);


	// Issue maybe arises in which program un-compiled. Work on maybe?
	if (strcmp(argv[1], "start") != 1) {
		int errorCheck;
		char command[100];

		if (strstr(argv[2], "./") != NULL) {
			errorCheck = system(program);
		} else {
			sprintf(command, "./%s", program);
			errorCheck = system(command);
		}

		if (errorCheck == 1) {
			printf("Error Running Program\n");
		}
	}

	return 0;
}
