#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	printf("Testing Program Works!\n");
	
	while(1) {
		printf("I am running\n");
		sleep(10);
	} // Dummy loop

	return 0;
}
