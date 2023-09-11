#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        // child (new process)
        printf("Hell, I am the child (pid:%d)\n", (int)getpid());
	char *myargs[2];
	myargs[0] = strdup("ls");
	myargs[1] = NULL;
	char *const envp[2] = {"", NULL};	

	//execvp(myargs[0], myargs);

	//execl("/bin/ls","ls",".", (char *) NULL);

	//execle("/bin/ls","ls",".", (char *)NUll, envp);
	
	//execlp("ls","ls",".",(char *)NULL);
	
	//execvp(myargs[0], myargs);

	execvpe(myargs[0], myargs,envp);

	printf("this shouldnt print out");
    }else{
        // parent goes down this path (original process)
        int rc_wait = wait(NULL);
	printf("Goodbye, yes, I am the parent of %d (rc_wait:%d)  (pid:%d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}
/***********************
Your Name: Nelson Xunic Cua
Question 1: There are so many variants because there are different conventions for passing arguments and also, each of the variants has different functionalities.
		Depending on what we need, we use the most coveniet.
***********************/
