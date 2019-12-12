#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <sys/vfs.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	struct statfs lstatfs;
	if(argc!=2)
	{
		printf("Usage : %s <path>\n", argv[0]);
		exit(1);
	}
	if(statfs((char*)argv[1], &lstatfs) == 0)
	{ 
		printf("block %ld\n", lstatfs.f_blocks*(lstatfs.f_bsize/1024));
                printf("avail %ld\n", lstatfs.f_bavail*(lstatfs.f_bsize/1024));
	}
	else
	{
		printf("statfs error\n");
                exit(1);
	}
}
