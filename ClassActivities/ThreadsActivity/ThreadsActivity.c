#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutex;
long sum = 0;

typedef struct Thread {
  pthread_t tid; /* thread id */
} Thread;

void* work(void* arg) {
  Thread* thread = (Thread*)arg;

  pthread_mutex_lock(&mutex);
  sum += (long)thread->tid;
  pthread_mutex_unlock(&mutex);

  printf("Thread ID: %p (%ld)\n", thread->tid, (long)thread->tid);
  return 0;
}

int main(int argc, char* argv[]) {
  pthread_mutex_init(&mutex, NULL);

  Thread* threads = (Thread*)malloc(5 * sizeof(Thread));

  for (int i = 0; i < 5; i++) {
    pthread_create(&threads[i].tid, NULL, work, &threads[i]);
    pthread_join(threads[i].tid, NULL);
  }

  printf("\nSum of ALL Thread IDs: %ld\n", sum);

  pthread_mutex_destroy(&mutex);
  free(threads);

  return 0;
}
