CC = gcc # Compiler Change
CFLAGS = -Wall -g # Compiler Checks
LIBS = -lm # Library List

# SRCS = Task-Master.c # Main/Source File
# OBJS = $(SRCS:.c=.o) # Generated Files

# TARG = TM # Executable File Name

# Generate Files
# all: $(TARG)

# $(TARG): $(OBJS)
#	$(CC) -o $(TARG) $(OBJS) $(LIBS)

# %.o: %.c
#	$(CC) $(CFLAGS) -c $*.c

# gcc -o TM Task-Master.c

# Clean Up Files
# clean:
#	rm -f $(OBJS) $(TARG) *~


all: Task-Master

Task-Master: Task-Master.o programHandler/programHandler.o dataTrail/outputLogger.o
	$(CC) $(CFLAGS) -o TM Task-Master.o programHandler/programHandler.o dataTrail/outputLogger.o $(LIBS)

Task-Master.o: Task-Master.c programHandler/programHandler.h dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c Task-Master.c -o Task-Master.o

programHandler.o: programHandler/programHandler.c programHandler/programHandler.h dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c programHandler/programHandler.c -o programHandler/programHandler.o

outputLogger.o: dataTrail/outputLogger.c dataTrail/outputLogger.h
	$(CC) $(CFLAGS) -c dataTrail/outputLogger.c -o dataTrail/outputLogger.o

clean:
	rm -f TM Task-Master.o programHandler/programHandler.o dataTrail/outputLogger.o
