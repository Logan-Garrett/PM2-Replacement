#include "outputLogger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

#define MAX_OUTPUT 1024

// I dont like how this is being run twice so will need to find a better way.
// It also is not working properly. Probably need to dyanmicaly allocate with like %m
void errorLogger(char *program) {
	/* 
	FILE *fp_input, *fp_output;
    	char output[MAX_OUTPUT];

    	fp_input = popen(program, "r");
    	if (fp_input == NULL) {
        	printf("Failed to run command\n");
   		exit(-1);
	}


    	fp_output = fopen("log.txt", "a");
    	if (fp_output == NULL) {
        	printf("Error opening file for writing\n");
    	}

    	while (fgets(output, sizeof(output), fp_input) != NULL) {
        	fprintf(fp_output, "%s", output); // Write the output to the file
    	}

	if (fp_output == NULL) {
        	printf("Error opening file for writing\n");
        	pclose(fp_input);
		exit(-1);
    	}

    	while (fgets(output, sizeof(output), fp_input) != NULL) {
        	fprintf(fp_output, "%s", output); 
    	}

    	fclose(fp_output);
    	pclose(fp_input);
	*/
}
