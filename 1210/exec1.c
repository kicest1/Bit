#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
//#include<stdlib.h>

extern char **environ;

int main(void)
{
	int ret;

	ret = execl("/home/anhyun/1210/adder","","30","40",NULL); // execl - process 를 execl 내용으로 대체함
	fprintf(stderr,"execl error: %s\n", strerror(errno));
	printf("execl:%d\n",ret);

	return 0;
}
