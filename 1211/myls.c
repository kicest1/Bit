#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

void printdir(char *dir,int depth)
{
	DIR *pdir;
	struct dirent *pde;
	struct stat buf;

	if((pdir=opendir(dir))==NULL){
		fprintf(stderr,"cannot open directory:%s\n",dir);
		return;
	}
	chdir(dir);
	while((pde=readdir(pdir))!=NULL){
			lstat(pde->d_name,&buf);
			if(S_ISDIR(buf.st_mode)){
				if(strcmp(".",pde->d_name) == 0 ||strcmp("..",pde->d_name) == 0){
					continue;
				}
				printf("%*s%s",depth,pde->d_name," ");
				printdir(pde->d_name,depth+4);
			}
			else printf("%*s%s",depth,pde->d_name," ");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	//if(argc[1]==-al)
	printdir(".",0);
	return 0;
}
