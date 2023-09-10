#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
	int fd = open("QUEST2.OUTPUT", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if(fd == -1){
		printf("Error: could not open file\n");
        	exit(1);	
	}else{
		printf("File opened successfully!\n");
	}
	//before fork
	char *message = "This is the parent before calling fork\n";
	write(fd, message, strlen(message));
	
	int rc = fork();
	if (rc < 0) {
     		printf("Error: fork failed.\n");
        	exit(1);
    	}
	
	else if (rc == 0){
	        // child (new process)
        	printf("hello, I am child (pid:%d)\n", (int)getpid());
	        char *childMessage="This is the child, after calling fork\n";
        	write(fd, childMessage,strlen(childMessage));
	        printf("writing to file from child\n");
	}else{
        	// parent goes down this path (original process)
	        printf("hello, I am parent of %d (pid:%d)\n",rc, (int)getpid());
	        char *parentMessage="This is the parent, after calling fork\n";
        	write(fd, parentMessage,strlen(parentMessage));
        	printf("Writing to file from parent\n");
    	}
	return 0;
}
/*****************************************************************************
Your Name: Nelson Xunic Cua
Question 1: Yes, both the parent and child can access the file descriptor
    returned by open(). 
Question 2:They can both write to the file as well.
****************************************************************************/
