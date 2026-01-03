#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define NUM_THREADS 4

void *hello(void * );

int main() {
  int j;
  pthread_t tid[NUM_THREADS];
  printf("My process ID %d\n", getpid());
  for (j = 0; j < NUM_THREADS; j++) {
    //create child process with name = tid[j], run hello function with j parameter.
    pthread_create(&tid[j], NULL, hello, (void *)&j);
  }

  for (int i = 0; i < NUM_THREADS; i++)
    //main function is done if all child process is done.
    pthread_join(tid[i], NULL);
  return 0;
}

void *hello(void * my_id) {
  printf("Hello World from branch thread %d\n", *(int * ) my_id);
}
