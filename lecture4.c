#include <stdio.h>
#include <stdlib.h>

double add_em_up(double *array,int N)
{
	int i;
	double sum=0.0;
	for (i=0;i<N;i++)
             sum += array[i];

	return(sum);
}
int main(int argc,char* argv[])
{
     	FILE *fp;
	int k,i,N;
	double *storage;
	char *filename;
	if (argc != 3)
	{
		printf("You did NOT give me enough parameter\n");
		printf("Peace\n");
		exit(0);
	}
        N=atoi(argv[1]);
	filename=argv[2];
	storage=(double *)malloc(N*sizeof(double));
	if (storage==NULL)
	{
		printf("Memory allocation failed\n");
		exit(0);
	}
	fp=fopen(argv[2],"r");
	if (!fp)
	{
		printf("File opening failed\n");
		exit(0);
	}
	fp=fopen(argv[2],"r");

        i=0;
        while ((i<N) && !feof(fp))
	{
	fscanf(fp,"%lf",&storage[i]);
	i++;
	}
#if DEBUG
	printf("Array loaded with %d values (?)\n",i);
#endif
	printf("Result: %lf\n",add_em_up(storage,i));
	return 0;
}

