#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	//파일 구조체 포인터 생성
	FILE *read_fp;
	char buffer[BUFSIZ+1];
	int chars_read;

	memset(buffer, '\0', sizeof(buffer));

	read_fp = popen("uname -a","r");
	if (read_fp != NULL)
	{
		//읽은 메세지를 출력
		chars_read = fread(buffer,sizeof(char), BUFSIZ, read_fp);
		if(chars_read>0)
		{
			printf("Output was:-\n%s\n",buffer);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}
