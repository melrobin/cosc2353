#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 
 int sum;
    struct more_information
    {
	    int first_parameter;
	    double second_parameter;
	    char *third_parameter;
    };
 
 void *runner(void *param);
 int main(int argc,char *argv[])
 {
    pthread_t tid; /* the thread id */
    pthread_attr_t attr ;/* thread attributes */
    struct more_information myinfo;
	
	if (argc != 2)
	{
	   printf("Usage: threadit <integer value >\n");
	   return -1;
	   }
	if (atoi(argv[1]) < 0)
	{
	    printf ("%d must be positive\n",atoi(argv[1]));
		return -1;
	}
     myinfo.third_parameter=argv[1];
     myinfo.second_parameter=3.14159;
   printf("I am running in the main program. Booo!\n"); 
	pthread_attr_init(&attr); /*set the default attributes */
	pthread_create(&tid,&attr,runner,&myinfo);
	//pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	
	printf("Sum = %d\n",sum);
	
	return 0;
	}
void *runner(void *param)
{
   int i, upper;
   struct more_information *argument=param;
   upper=atoi(argument->third_parameter);
   sum = 0;
   printf("In fact another parameter is %f!\n",argument->second_parameter); 
   for (i=1; i<=upper;i++)
      sum += i;
printf("Thread finished...going back to main\n");	  
	pthread_exit(0);
}
