#include "outputLogger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>

#define MAX_INPUT  512
#define MAX_OUTPUT 1024

// I dont like how this is being run twice so will need to find a better way.
// It also is not working properly. Probably need to dyanmicaly allocate with like %m
void errorLogger(char *program) {
	printf("Error being logged for: %s\n", program);
}
