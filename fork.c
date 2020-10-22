#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NFORKS 50000

void do_nothing()
{
	int i;
	i = 0;
}

int main(int argc, char *argv[])
{
	int pid, j, status;
	time_t start_time = clock();

	for (j = 0; j < NFORKS; j++)
	{

		/*** error handling ***/
		if ((pid = fork()) < 0)
		{
			printf("fork failed with error code= %d\n", pid);
			exit(0);
		}

		/*** this is the child of the fork ***/
		else if (pid == 0)
		{
			do_nothing();
			exit(0);
		}

		/*** this is the parent of the fork ***/
		else
		{
			waitpid(pid, status, 0);
		}
	}

	time_t end_time = clock();

	float runTimeProcess = (float)(end_time-start_time)/CLOCKS_PER_SEC;
	printf("The processes run time is %f\n", runTimeProcess);

	return 0;
}

