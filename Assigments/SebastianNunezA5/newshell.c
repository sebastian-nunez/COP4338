/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 5)
 * DATE: 11/21/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This program prints the letters 'a' - 'z' to the std output stream
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 20
#define BUFSIZ 1024

void execute(char* cmd, char* args[]) {
  int pid;

  if (strcmp(cmd, "letters") == 0) {
    pid = fork();
    if (pid == 0) { /* child process */
      execvp("./letters", NULL);
      /* return only when exec fails */
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { /* parent process */
      waitpid(pid, NULL, 0);

    } else { /* error occurred */
      perror("fork failed");
      exit(1);
    }
  } else if (strcmp(cmd, "numbers") == 0) {
    pid = fork();
    if (pid == 0) { /* child process */
      execvp("./numbers", NULL);
      /* return only when exec fails */
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { /* parent process */
      waitpid(pid, NULL, 0);

    } else { /* error occurred */
      perror("fork failed");
      exit(1);
    }
  } else if (strcmp(cmd, "firstname") == 0) {
    pid = fork();
    if (pid == 0) { /* child process */
      execl("./firstname", "./firstname", args[0], NULL);
      /* return only when exec fails */
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { /* parent process */
      waitpid(pid, NULL, 0);

    } else { /* error occurred */
      perror("fork failed");
      exit(1);
    }
  } else if (strcmp(cmd, "userinput") == 0) {
    pid = fork();
    if (pid == 0) { /* child process */
      execl("./userinput", NULL);
      /* return only when exec fails */
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { /* parent process */
      waitpid(pid, NULL, 0);

    } else { /* error occurred */
      perror("fork failed");
      exit(1);
    }
  } else if (strcmp(cmd, "letters > filename") == 0) {
    int fd[2], status;

    pipe(fd);
    pid = fork();

    if (pid == 0) {    /* child process */
      dup2(fd[1], 1);  // output of letters goes to the pipe
      close(fd[0]);

      execl("./letters", NULL);
      /* return only when exec fails */
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { /* parent process takes the output from pipe and prints it to a file*/
      waitpid(pid, NULL, 0);
      close(fd[1]);

      int outfile = open(args[0], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);  // create outfile for writing

      char buffer[BUFSIZ];
      int length = read(fd[0], buffer, sizeof(char) * BUFSIZ);

      if (length > 0) {
        write(outfile, buffer, length);  // write to outfile
      }
      close(outfile);
    } else { /* error occurred */
      perror("fork failed");
      exit(1);
    }

    close(fd[0]);
    close(fd[1]); /* this is important! close both file descriptors on the pipe */

    while ((pid = wait(&status)) != -1) /* pick up all the dead children */
      fprintf(stderr, "process %d exits with %d\n", pid, status);
  } else if (strcmp(cmd, "letters | userinput") == 0) {
    int fd[2], status;

    pipe(fd);

    switch (pid = fork()) {
      case 0:
        dup2(fd[1], 1);                               // output of cat goes to stdout
        close(fd[0]);                                 // close input side
        execl("./letters", NULL);                     // exec command
        fprintf(stderr, "%s failed\n", "./letters");  // failure
      default:
        waitpid(pid, NULL, 0); /* parent does nothing */
        break;
      case -1:
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    switch (pid = fork()) {
      case 0:
        dup2(fd[0], 0);                                // make input stdin
        close(fd[1]);                                  // close output side
        execl("./userinput", NULL);                    /* run the command */
        fprintf(stderr, "%s failed\n", "./userinput"); /* command failed! */
      default:
        waitpid(pid, NULL, 0); /* parent does nothing */
        break;
      case -1:
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]); /* this is important! close both file descriptors on the pipe */

    while ((pid = wait(&status)) != -1) /* pick up all the dead children */
      fprintf(stderr, "process %d exits with %d\n", pid, status);
  } else if (strcmp(cmd, "firstname | userinput") == 0) {
    int fd[2], status;

    pipe(fd);

    switch (pid = fork()) {
      case 0:
        dup2(fd[1], 1);  // output of cat goes to stdout
        close(fd[0]);
        printf("here");                                      // close input side
        execl("./firstname", "./firstname", args[0], NULL);  // exec command
        fprintf(stderr, "%s failed\n", "./firstname");       // failure
      default:
        waitpid(pid, NULL, 0); /* parent does nothing */
        break;
      case -1:
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    switch (pid = fork()) {
      case 0:
        dup2(fd[0], 0);                                // make input stdin
        close(fd[1]);                                  // close output side
        execl("./userinput", NULL);                    /* run the command */
        fprintf(stderr, "%s failed\n", "./userinput"); /* command failed! */
      default:
        waitpid(pid, NULL, 0); /* parent does nothing */
        break;
      case -1:
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]); /* this is important! close both file descriptors on the pipe */

    while ((pid = wait(&status)) != -1) /* pick up all the dead children */
      fprintf(stderr, "process %d exits with %d\n", pid, status);
  } else if (strcmp(cmd, "exit") == 0) {
    exit(0);
  } else {
    printf("Invalid command!");
    exit(1);
  }
}

int main(int argc, char* argv[]) {
  int cmd;

  while (1) {
    printf("1 letters\n");
    printf("2 numbers\n");
    printf("3 firstname\n");
    printf("4 userinput\n");
    printf("5 letters > filename\n");
    printf("6 letters | userinput   (letters piped to userinput)\n");
    printf("7 firstname | userinput   (names piped to userinput)\n");
    printf("8 exit  (your program should end by leaving the infinite loop.)\n");

    scanf("%d", &cmd);

    switch (cmd) {
      case 1:
        execute("letters", NULL);
        break;
      case 2:
        execute("numbers", NULL);
        break;
      case 3:
        printf("Enter your firstname :: ");
        char name[BUFSIZ];
        scanf("%s", name);

        char* args[] = {name};
        execute("firstname", args);
        break;
      case 4:
        execute("userinput", NULL);
        break;
      case 5:
        printf("Enter the filename :: ");
        char filename[BUFSIZ];
        scanf("%s", filename);

        char* args1[] = {filename};
        execute("letters > filename", args1);
        break;
      case 6:
        execute("letters | userinput", NULL);
        break;
      case 7:
        printf("Enter your firstname :: ");
        char name1[BUFSIZ];
        scanf("%s", name1);

        char* args2[] = {name1};
        execute("firstname | userinput", args2);
        break;
      case 8:
        execute("exit", NULL);
        break;
      default:
        printf("Invalid command!\n");
    }
  }

  return 0;
}
