#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t child1, child2;

  child1 = fork();
  if (child1 < 0) {
    perror("Fork creation for child '1' failed!");
    exit(-1);
  }

  if (child1 == 0) {
    printf("Running 'ls -l'...\n");
    sleep(2);
    execlp("ls", "ls", "-l", NULL);

    perror("Exec for child process '1' failed!");
    exit(-1);
  } else {
    child2 = fork();
    if (child2 < 0) {
      perror("Fork creation for child '2' failed!");
      exit(-1);
    }

    if (child2 == 0) {
      printf("Running 'cat forkchildren.c'...\n");
      sleep(4);
      execlp("cat", "cat", "forkchildren.c", NULL);

      perror("Exec for child process '2' failed!");
      exit(-1);
    } else {
      printf("Parent process... waiting for children processes to finish!\n");
      sleep(10);
      printf("Parent process has finished!\n");
    }
  }

  return 0;
}
