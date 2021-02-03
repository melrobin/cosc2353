#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	char *signature;
	unsigned short width,height;

	signature=(char *)calloc(7,sizeof(char));
	fp=fopen("earth.gif","rb");
	fread(signature,1,6,fp);
        fread(&width,sizeof(unsigned int),1,fp);
        fread(&height,sizeof(unsigned int),1,fp);
	printf("Signature: %s\n",signature);
	printf("Width: %d\n",width);
	printf("Height: %d\n",height);
	free(signature);
	fclose(fp);
	return 0;
}
