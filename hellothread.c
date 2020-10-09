#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_THREADS 10
int error;
int counter;
pthread_t thread_id[MAX_THREADS]; 

struct info{
  int id;
};

void* worker(void * id){
  int tid = (int)id;
  printf("Hello world! I am thread %d\n", tid + 1);  
  /*error = pthread_join(thread_id[tid], NULL);
  if(error != 0){
    printf("Thread creation unsuccessful. retval = %d\n", error);
    pthread_exit(NULL);
  }else{
    printf("Thread successful. Terminating thread %d. retval = %d\n", tid + 1, error);
    pthread_exit(NULL);
  }*/
}

int main(){
  int n;
  printf("Enter integer n (between 1 and 10): ");
  scanf("%d", &n);
  if((n < 1) || (n > 10)){
    printf("Invalid input. Exiting program.\n");
    exit(0);
  }
  
  for(int i = 0; i < n; i++){
    pthread_create(&thread_id[i], NULL, worker, (void*)i);
    printf("Creating thread %d\n", i + 1);
  }
  for(int i = n - 1; i >= 0; i--){
    error = pthread_join(thread_id[i], NULL);
    if(error != 0){
      printf("Thread creation unsuccessful. retval = %d\n", error);
      pthread_exit(NULL);
    }else{
      printf("Thread successful. Terminating thread %d. retval = %d\n", i + 1, error);
    }
  }
}
