#include "programHandler.h"
#include "/home/logan/Desktop/git/PM2-Replacement/dataTrail/outputLogger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>

#define MAX_LENGTH 256
#define MAX_BUF 1024

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

char *programName() {
	char programHolder[MAX_LENGTH];
        char *program;
        printf("Enter Program Name: ");
        if (fgets(programHolder, sizeof(programHolder), stdin) != NULL) {
                if (programHolder[strlen(programHolder) - 1] == '\n') {
                        programHolder[strlen(programHolder) - 1] = '\0';
                }
        }

        program = strdup(programHolder);
	return program;
}


int currentProcess(char *name) {
	DIR *dir;
    	struct dirent *entry;
    	FILE *fp;
    	char path[MAX_BUF];
    	char pname[MAX_BUF];
	int pid;

    	dir = opendir("/proc");
    	if (dir == NULL) {
        	perror("opendir");
        	exit(-1);
    	}

   	while ((entry = readdir(dir)) != NULL) {
        	if (entry->d_type == DT_DIR) {
            		int pid_val = atoi(entry->d_name);

            		if (pid_val != 0) {
                		snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
                		fp = fopen(path, "r");
                		if (fp != NULL) {
                    			fscanf(fp, "%s", pname);
                    			fclose(fp);
					if (strcmp(name, pname) == 0) {
						pid = atoi(entry->d_name);
                    				//printf("PID: %s, Name: %s\n", entry->d_name, pname);
                			}
				}
            		}
        	}
    	}
	
    	closedir(dir);
	return pid;
}

void stopProgram(int pid) {
	int status = kill(pid, SIGKILL);
	
	if (status != 0) {
		printf("Unable to terminate process with PID %d.\n", (int)pid);
		exit(-1);
	}
}

void statusOfProgram(int pid) {
	if (pid < 0) {
		printf("Program not running.\n");
	} else {
		printf("Program Running.\n");
	}
};
