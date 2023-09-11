#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
 
int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
    // child: redirect standard output to a file
    printf("I am printing from the child,(PID:%d), before closing STDOU_FILENO\n", (int) getpid());
    close(STDOUT_FILENO); 
    // open("theoutput.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("I am printing from the child\n");
    
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
	printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
    }
    return 0;
}
/****************
Nelson Xunic Cua
Question 1: if the child calls printf() to print some output after closing the descripto, we don't see any output
*****************/
