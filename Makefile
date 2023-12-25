CC = gcc # Compiler Change
CFLAGS = -Wall -g # Compiler Checks
LIBS = -lm # Library List

SRCS = Task-Master.c # Main/Source File
OBJS = $(SRCS:.c=.o) # Generated Files

TARG = TM # Executable File Name

# Generate Files
all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $*.c

# gcc -o TM Task-Master.c

# Clean Up Files
clean:
	rm -f $(OBJS) $(TARG) *~

