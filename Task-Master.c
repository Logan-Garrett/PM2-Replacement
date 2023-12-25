#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("Welcome to Task Master.\n");

	char *action = argv[1];
	printf("Action being performed: %s\n", action);

	return 0;
}
