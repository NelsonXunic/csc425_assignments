#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("hello world (pid:%d)\n", (int) getpid());
	int x = 100;
	int rc = fork();
	if (rc < 0) {
		 // fork failed
		 fprintf(stderr, "fork failed\n");
		 exit(1);
	 } else if (rc == 0) {
		 // child (new process)
		 printf("hello, I am child (pid:%d)\n", (int) getpid());
		printf("value of x, x=%d\n", x);
		x=50;
		printf("Hey, we changed the value of x in the child copy: new  x =%d\n", x);
	 } else {
		 // parent goes down this path (main)
		 printf("hello, I am parent of %d (pid:%d)\n",
		 rc, (int) getpid());
		printf("value of x, x=%d\n", x);
		x =75;
		printf("we changed the value of x in the parent copy: new x x = %d\n", x);
	 }
	 return 0;
}
/**************************************************************
Your name: Nelson Xunic Cua
Question 1: Right after the fork, the value of the varible in the child has the same value of the variable in the parent. The child is a copy of the parent.
Question 2: Since both the parent and the child both have their own copy of the variable, changing the value of x in one doesnot change the value of x in the other.
**************************************************************/
