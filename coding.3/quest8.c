#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
        printf("Hello World, PID %d\n", (int) getpid());

        int pipefd[2];
        char buf;
        if (pipe(pipefd) == -1)
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
                close(pipefd[1]);          /* Close unused write end */

		while (read(pipefd[0], &buf, 1) > 0)
                         write(STDOUT_FILENO, &buf, 1);

                write(STDOUT_FILENO, "\n", 1);
                close(pipefd[0]);
                _exit(EXIT_SUCCESS);
        } else {
                int rc_2 = fork();
                if (rc_2 == -1) {
                        printf("Error: second fork() failed.\n");
                        exit(1);
                } else if (rc_2 == 0) { /* Second child  writes argv[1] to pipe */
                        close(pipefd[0]);          /* Close unused read end */
                        write(pipefd[1], argv[1], strlen(argv[1]));
                        close(pipefd[1]);          /* Reader will see EOF */
                        wait(NULL);                /* Wait for child */
                        exit(EXIT_SUCCESS);
                }else{
                        int rc_wait = wait(NULL);
                        printf("\n hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
                }
        }
        return 0;
}
