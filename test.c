#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	printf("Test Running.\n");
	while(1) {
		// printf("Testing Program Works!\n");
		sleep(5);
	}

	/*	
	printf("I am running\n");
	sleep(5);

	printf("I am running\n");
        sleep(5);

	printf("I am running\n");
        sleep(5);

	printf("I am running\n");
        sleep(5); */

	return 0;
}
