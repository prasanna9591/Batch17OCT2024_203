#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void printhello();
int main()
{
	pthread_t tid;
	int status=0;
	printf("\n IN the main function\n");
	printf("\n I am main process/thread/program\n");
	status = pthread_create(&tid,NULL,printhello,NULL);
	pthread_join(tid,NULL);
	printf("\n After completing main\n");
	return 0;
}
void printhello()
{
	printf("\n Hello World\n");
}

