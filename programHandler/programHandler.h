#ifndef PROGRAMHANDLER_H
#define PROGRAMHANDLER_H

void testFunction();

void startProgram();

void inputFormat(char *program);

char *programName();

int currentProcess(char *name);

void stopProgram(int pid);

void statusOfProgram(int pid);
#endif
