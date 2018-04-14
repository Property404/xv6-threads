#include "assert.h"
#include "fcntl.h"
// tEst 3
// clone copies file descriptors but doesn't share
void worker(void *arg_ptr);
int newfd = 0;

int
main(int argc, char*argv[])
{
	void *stack = malloc(PGSIZE*2);
	assert(stack != NULL);
	if((uint)stack%PGSIZE)
		stack = stack + (4096 - (uint)stack %PGSIZE);
	int fd = open("tmp", O_WRONLY|O_CREATE);
	assert(fd == 3);
	int clone_pid = clone (worker, 0, stack);
	assert(clone_pid > 0 );
	while(!newfd);
	assert(write(newfd, "goodbye\n", 8) == -1);
	test_passed();
	exit();
}

void worker(void *arg_ptr){
	assert(write(3, "hello\n", 6) == 6);
	newfd = open("tmp2", O_WRONLY|O_CREATE);
	exit();
}
