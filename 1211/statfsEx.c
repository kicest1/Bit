#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/vfs.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{printf("Usage : %s <path>\n", argv[0]);exit(1);}
	int blocks;
	int bavail;
	struct statfs lstatfs;

	if(statfs((char*)argv[1], &lstatfs) == 0)
	{
		blocks = lstatfs.f_blocks * (lstatfs.f_bsize/1024); 
                bavail  = lstatfs.f_bavail * (lstatfs.f_bsize/1024);
		printf("1K-blocks : %d\nAvailable : %d\n", blocks, bavail);
	}
	else
	{
		perror("statfs error\n");
		exit(1);
	}

	return 0;
}
