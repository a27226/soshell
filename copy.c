#include "shell.h"

void lowlevelcopy(int in, int out, int size)
{
	int n;
	char *buf = (char *)malloc(size);
	while((n=read(in,buf,size))>0)
		write(out,buf,size);
	free(buf);
}

void *wrapperCopy(void *args)
{
	myType *data = (myType *) args;
	lowlevelcopy(data->in,data->out,data->size);
	free(args);
	printf("Copy finished.");
	return(NULL);
}
