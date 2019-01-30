
// C program to demonstrate working of Semaphores 

#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
  
void* thread(void* arg) 
{ 
    //wait 
    sem_wait(&mutex); 
    printf("\nEntered..\n"); 
  
    //critical section 
    //sleep(4); 

    printf(":::::::::::::::::::::::THREAD EXECUTION UNDER PROGRESS:::::::::::::::::::::::::::%d\n",mutex);  

    //signal 
    printf("\nJust Exiting...\n"); 
    sem_post(&mutex); 
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 10); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    //sleep(5); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 


/*
:::::::::::::::::::::::::::::::CONCEPT OF COUNTER SEMAPHORE:::::::::::::::::::::::::::::::::::

P(Semaphore s) 
{ 
    s = s - 1; 
    if (s < 0) { 
  
        // add process to queue 
        block(); 
    } 
} 
  
V(Semaphore s) 
{ 
    s = s + 1; 
    if (s >= 0) { 
  
        // remove process p from queue 
        wakeup(p); 
    } 
} 
*/
