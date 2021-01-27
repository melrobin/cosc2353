#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_it_out(char *x)
{
	printf("%s\n",x);
}

int main(int argc, char *argv[])
{
	FILE *fp;
        int i,N;
	char *filename; /*This is a string */
	char *string_to_write;
	double an_array[25]; /*Statically allocated */
	double *a_dynamically_allocated_array; /*to be dynamically allocated */
	struct student
	{
		char *ip_address;
		char grade;
		double height;
	};

	struct student Johnny; /*Johnny is actually a real student variable */

	Johnny.ip_address="192.168.4.3"; /* You can use the . for actual variables */
	Johnny.grade='A';
	Johnny.height=2.0;

	struct student *Charles; /*This is a pointer to a struct student */
        Charles=(struct student *)malloc(sizeof(struct student));

        Charles->height=1.5; /*Pointers to structs must use ->  */
        print_it_out(Johnny.ip_address);
	/*Assign some values */
	an_array[0]=-16.3;
	an_array[24]=0.35;
	a_dynamically_allocated_array=(double *)malloc(25*sizeof(double));
/*	for (i=0;i<25;i++)
	{
		printf("%f\t%f\n",an_array[i],a_dynamically_allocated_array[i]);
	}
	printf("This is actually the pointer value %p\n",a_dynamically_allocated_array);
	printf("This is actually the pointer value %p\n",&a_dynamically_allocated_array[2]);
*/

	return 0;
}


