#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int pid, status;
	int fd[2];

	pipe(fd);
    
    // grep main
	switch (pid = fork())
	{
		case 0:
			dup2(fd[0], 0);	// make input stdin
			close(fd[1]); 		// close output side
			execl("/bin/grep", "grep", "main", 0);	/* run the command */
			fprintf(stderr,"%s failed\n", "grep main");	/* command failed! */
		default: /* parent does nothing */
			break;
		case -1:
			fprintf(stderr, "fork failed\n");
			exit(1);
	}

    // cat minishell.c
	switch (pid = fork())
	{
		case 0:
			dup2(fd[1], 1); // output of cat goes to stdout
			close(fd[0]); // close input side
			execl("/bin/cat", "cat", "minishell.c", 0); // exec command
			fprintf(stderr,"%s failed\n", "cat minishell.c");	// failure
		default: /* parent does nothing */
			break;
		case -1:
			fprintf(stderr,"fork failed\n");
			exit(1);
	}

	close(fd[0]); close(fd[1]); 	/* this is important! close both file descriptors on the pipe */

	while ((pid = wait(&status)) != -1)	/* pick up all the dead children */
		fprintf(stderr, "process %d exits with %d\n", pid, status);
	exit(0);
}
