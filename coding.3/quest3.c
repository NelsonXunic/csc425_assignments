#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("Hello\n");
	printf("That was me, the child (pid:%d)\n", (int)getpid());
    }
    else
    {
	sleep(10);
        // parent goes down this path (original process)
        printf("Goodbye\n");
	printf("Yes that was me, the parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}
/***********************
Your Name: Nelson Xunic Cua
Question 1: Yes, I used sleep().
***********************/
