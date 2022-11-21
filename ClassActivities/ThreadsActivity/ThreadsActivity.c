#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Thread {
  pthread_t tid; /* thread id */
  int idx;       /* thread index (0 .. p-1) */
} Thread;

pthread_mutex_t mutex;
long sum = 0;

void* work(void* arg) {
  Thread* thread = (Thread*)arg;

  pthread_mutex_lock(&mutex);
  sum += (long)thread->tid;
  pthread_mutex_unlock(&mutex);

  printf("Thread ID: %p\n", thread->tid);
  return 0;
}

int main(int argc, char* argv[]) {
  Thread* thread;

  pthread_mutex_init(&mutex, NULL);

  thread = (Thread*)malloc(sizeof(Thread));
  for (int i = 0; i < 5; i++) {
    thread[i].idx = i;
    pthread_create(&thread[i].tid, NULL, work, &thread[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(thread[i].tid, NULL);
  }

  printf("%ld\n", sum);

  pthread_mutex_destroy(&mutex);
  free(thread);
  return 0;
}
