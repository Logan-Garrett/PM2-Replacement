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


# Define your targets
all: Task-Master

# Task-Master binary compilation
Task-Master: Task-Master.o cHandler.o
	$(CC) $(CFLAGS) -o TM Task-Master.o cHandler.o

# Task-Master object file compilation
Task-Master.o: Task-Master.c cHandler.h
	$(CC) $(CFLAGS) -c Task-Master.c

# cHandler object file compilation
cHandler.o: cHandler.c cHandler.h
	$(CC) $(CFLAGS) -c cHandler.c

# Clean rule to remove generated files
clean:
	rm -f TM Task-Master.o cHandler.o

