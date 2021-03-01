#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex;
long long sum=0;

struct data
{
	long long N1,N2,num_iters;
	int offset;
};
void *counting_thread(void *x)
{
	struct data *argument=x;
        long long upper=argument->N1;
	int i;
	int offset=argument->offset;
	
	for (i=1; i<=upper;i++)
	{
		pthread_mutex_lock(&mutex);
		sum+=offset;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	pthread_t tid1,tid2,tid3,tid4;
        struct data param1,param2;
	if (argc != 3)
	{
		printf("Usage: ./executable <limit 1> <limit 2>\n");
		exit(0);
	}
	if (atoi(argv[1])<0 || atoi(argv[2]) <0)
	{
		printf("We need positive integers!\n");
		exit(0);
	}
	param1.N1=atoi(argv[1]);
	param1.N2=atoi(argv[2]);
	param1.offset=1;
	param1.num_iters=1000000000;
	param2.N1=atoi(argv[1]);
	param2.N2=atoi(argv[2]);
	param2.offset=-1;
	param2.num_iters=1000000000;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&tid1,NULL,counting_thread,&param1);
	pthread_create(&tid2,NULL,counting_thread,&param2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("Sum: %lld\n",sum);

	return 0;
}

