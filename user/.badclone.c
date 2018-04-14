#include "assert.h"
// clone with bad arguments

void worker(void* b)
{
	printf(1,"%p\n", b);
	exit();
}

int main(int argc, char*argv[])
{
	void *stack = malloc(PGSIZE*2);
	assert(stack != NULL);
	if(((uint)stack % PGSIZE) == 0)
		stack += 4;
	assert(clone(worker, 0, stack) == -1);

	stack = sbrk(0);
	if((uint)stack%PGSIZE)
		stack = stack + (PGSIZE - (uint)stack %PGSIZE);
	sbrk(((uint)stack - (uint)sbrk(0))+PGSIZE/2);
	assert((uint)stack %PGSIZE == 0);
	assert((uint)sbrk(0) - (uint)stack == PGSIZE/2);

	assert(clone(worker, 0, stack) == -1);

	test_passed();
	exit();
}
