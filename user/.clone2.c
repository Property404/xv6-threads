#include "assert.h"
// Test 2
// // Clone and pass one argument
//

volatile int arg = 55;
volatile int global = 1;
void worker(void * arg_ptr);

int main(int argc, char*argv[])
{
	void *stack = malloc(PGSIZE*2);
	assert(stack != NULL);
	if((uint)stack%PGSIZE)
		stack+=(4096 - (uint)stack %PGSIZE);
	int clone_pid = clone(worker, (void*)&arg, stack);

	assert(clone_pid > 0);
	while(global != 55);
	assert(arg == 1);
	test_passed();
	exit();
}

void
worker(void * arg_ptr){
	int tmp = *(int*)arg_ptr;
	*(int*)arg_ptr = 1;
	assert(global==1);
	global = tmp;
	exit();
}
