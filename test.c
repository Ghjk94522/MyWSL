#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int g = 0; // a global variable can be changed in threads

void *myThreadFun(void *vargp){
	// Store the value argument passed to this thread
	int *myid = (int *)vargp;
	// Let us create a static variable to observe its changes
	static int s = 0;
	// Change the static and global variables
	++s; ++g;
	// Print the arguments, static and global variables
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main(){
	int i;
	pthread_t tid;
	// Let us creat three threads
	for( i = 0; i < 3; i++ )
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid);

	pthread_exit(NULL);
	return 0;
}
