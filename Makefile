CC = gcc # Compiler Change
CFLAGS = -Wall -g # Compiler Checks
LIBS = -lm # Library List

all: Task-Master

Task-Master: Task-Master.o programHandler/programHandler.o programHandler/helperFunctions.o dataTrail/outputLogger.o
	$(CC) $(CFLAGS) -o TM Task-Master.o programHandler/programHandler.o programHandler/helperFunctions.o dataTrail/outputLogger.o $(LIBS)

Task-Master.o: Task-Master.c programHandler/programHandler.h dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c Task-Master.c -o Task-Master.o

programHandler/programHandler.o: programHandler/programHandler.c programHandler/programHandler.h dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c programHandler/programHandler.c -o programHandler/programHandler.o -IdataTrail

programHandler/helperFunctions.o: programHandler/helperFunctions.c programHandler/helperFunctions.h
	$(CC) $(CFLAGS) -c programHandler/helperFunctions.c -o programHandler/helperFunctions.o

dataTrail/outputLogger.o: dataTrail/outputLogger.c dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c dataTrail/outputLogger.c -o dataTrail/outputLogger.o

clean:
	rm -f TM Task-Master.o programHandler/programHandler.o programHandler/helperFunctions.o dataTrail/outputLogger.o test

test:
	$(CC) $(CFLAGS) -o test test.c
