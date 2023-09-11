#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    sleep(1);
    int wc = wait(NULL);
    printf("The value of return from wait in child program is %d\n", wc);
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
           rc, wc, (int) getpid());
    }
    return 0;
}
/****************************************
Nelson Xunic Cua
Question 1: when used in the parent wait() returns the PID of the child process that finished
Question 2: If we use  wait() in the child, it returns -1. There is an error because the current child process does not have child process to wait for.
***************************************/
