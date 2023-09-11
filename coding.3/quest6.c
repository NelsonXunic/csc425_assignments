#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
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
    } else {
        // parent goes down this path (original process)
        int wc = waitpid(rc, 0,0);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
           rc, wc, (int) getpid());
    }
    return 0;
}
/****************
Nelson Xunic Cua
Question 1: waitpid() would be useful when the parent process has more than one child. In this case, we want to specify the id of the child we want to wait to be completed.
*****************/
