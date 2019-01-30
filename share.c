#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>



int main ()
{
  int segment_id;
  char bogus;
  char* shared_memory;
  struct shmid_ds shmbuffer;
  int segment_size;
  const int shared_segment_size = 0x1000;

  /* Allocate a shared memory segment.  */
  segment_id = shmget (IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

  /* Attach the shared memory segment.  */
  printf("Shared memory segment ID is %d\n", segment_id);


  	
   	
  		shared_memory = (char*) shmat(segment_id, 0, 0);
  		printf ("shared memory attached at address %p\n", shared_memory);

        

  /* Determine the segment's size. */
  /*
  shmctl (segment_id, IPC_STAT, &shmbuffer);
  segment_size  =               shmbuffer.shm_segsz;
  printf ("segment size: %d\n", segment_size);
  */
  /* Write a string to the shared memory segment.  */



  		sprintf (shared_memory, "Hello, world.");


  /* Detach the shared memory segment.  */
                
  		shmdt (shared_memory);
  		printf("Wrote Hello World to the segment\n");

  return 0;

}

/*

OUTPUT:

Shared memory segment ID is 3047432
shared memory attached at address 0x7f6bdd988000
Wrote Hello World to the segment

*/



