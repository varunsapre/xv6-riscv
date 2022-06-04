#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user/thread.h"
#include "kernel/spinlock.h"

//Implementation of thread create function
int thread_create(void *(*start_routine)(void*), void *arg) {
	
	//Initialize thread ID variable which is similar to PID
	int threadID;
	
	//Initialize stack size
	int stack_size = 4096 * sizeof(void);
	
	//Initialize separate stack space, to keep separate stack for thread created by parent.
	void* stack = (void*)malloc(stack_size);
	
	//Calling clone function that creates a new thread with new stack but shared address space and file directives
	threadID  = clone(stack,stack_size);
	
	if(threadID == 0) {
		//Call routing is correct thread ID is returned i.e child thread
		(*start_routine) (arg);
		exit(0);
	}

	return 0;
}

//Implementation of lock
void lock_init(lock_t *lock)
{
	*lock = 0;
}

void 
lock_acquire(lock_t *lock)
{
	while(__sync_lock_test_and_set(lock, 1) != 0);
	__sync_synchronize();
}

void 
lock_release(lock_t *lock)
{
	__sync_synchronize();
	__sync_lock_release(lock,0);
}