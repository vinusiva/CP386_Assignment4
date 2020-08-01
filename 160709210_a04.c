/*Vinuyaa Sivanathan
Cp386*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>

typedef struct process //represents a single thread, you can add more members if required
{
	int max;
} Process;


int main(int argc, char *argv[])
{

	Process* processes = NULL;

	printf("Number of Customers:5\n");
	printf("Currently Available resources:%s %s %s %s\n",argv[1],argv[2],argv[3],argv[4]);

	return 0;
}


