#include<stdio.h>
#include<time.h>

int main(void)
{
	time_t t = time(NULL);
	struct tm *st_time;
	char buff[1000];
	st_time = localtime(&t);

	strftime(buff,1000,"%Y%m%d_%H%M%S\n",st_time);

	printf(buff);
	return 0;

}
