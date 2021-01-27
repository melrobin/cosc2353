#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float integrate_x_dx(float ,float );
int is_less_than(int x,int N)
{
	/* Return 0 if x is less than N otherwise return 1 */
	if (x<N)
		return 0;
	else
		return 1;
}
int is_equal_to(int x,int N)
{
	/* Return 0 if x is not equal to N otherwise return 1 */
	if (x != N)
		return 0;
	else
		return 1;
}
int main(int argc,char *argv[])
{
	float integral,radius;
	int i,N,sum=0;
	FILE *fp1,*fp2;

	if (argc < 5)
	{
		printf("You did not give me enough arguments!  Peace!\n");
		exit(0);
	}
	integral=integrate_x_dx(0,3);
	N=atoi(argv[1]);
	radius=atof(argv[2]);
	fp1=(FILE *)fopen(argv[3],"w");
	fp2=(FILE *)fopen(argv[4],"w");
	//fprintf(fp1,"I wrote some data to a file\n");
	//printf("The integral is: %f\n",integral);
	/* sum(i) from 1 to N is N(N+1)/2 */
	printf("The first command line argument, argv[0] is: %s\n",argv[0]);
        for (i=1;i<=N;i++)
	{
		sum = sum + i;
	//	printf("I am on iteration number: %d and the current sum is %d\n",i,sum);
	}
        fprintf(fp1,"My final answer is %d\n",sum);
        fprintf(fp2,"Meanwhile the circumfernce for the radius you gave is %f\n",6.28*radius);
//	fclose(fp1);
//	fclose(fp2);
        return 0;
}

float integrate_x_dx(float a,float b)
{
	float temp1,temp2;
	temp1=a*a/2;
	temp2=b*b/2;
	return(temp2-temp1);
}
