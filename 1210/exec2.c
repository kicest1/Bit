#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>

extern char **environ;

int main(void)
{
	int ret;
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		pid = getpid();
                printf("pid=%d\n",pid);
		ret = execl("/home/anhyun/1210/copy","/home/anhyun/1210/copy",NULL); // execl - process 를 execl 내용으로 대체함
		fprintf(stderr,"execl error: %s\n", strerror(errno));
		printf("execl:%d\n",ret);
		sleep(1);
	}
	else
	{
		pid = getpid();
		printf("pid=%d\n",pid);
		wait();
		kill(1,1);
	}
	return 0;
}
