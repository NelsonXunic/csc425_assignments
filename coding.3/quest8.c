#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	printf("Hello World, PID %d\n", (int) getpid());

	int pip[2];	
	char instring[20];
	if (pipe(pip) == -1)
	{
		perror("Pipe failed");
		exit(1);
	} 

	int rc = fork();
    	if (rc < 0) {
        	printf("Error: call to fork() failed.\n");
        	exit(1);
    	} else if (rc == 0) {
       		printf("hello, I am child (pid:%d)\n", (int) getpid());
   		write(pip[1], "Hi Mom!", 7); 
	} else {
		int rc_2 = fork();
        	if (rc_2 == -1) {
            		printf("Error: second fork() failed.\n");
            		exit(1);
        	} else if (rc_2 == 0) {
        	    	read(pip[0], instring, 7);
        	}else{
			int rc_wait = wait(NULL);
			printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
    		}
	}
    	return 0;
}
