#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
//#include<stdlib.h>

extern char **environ;

int main(void)
{
	int ret;
	pid_t pid;

	pid = getpid();
	printf("pid=%d\n",pid);
	pid = fork();
	wait();
	ret = execl("/bin/ps","bin/ps",NULL); // execl - process 를 execl 내용으로 대체함
	fprintf(stderr,"execl error: %s\n", strerror(errno));
	printf("execl:%d\n",ret);
	printf("pid=%d\n",pid);

	return 0;
}
