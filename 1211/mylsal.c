#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

void printls(char *dir,int depth)
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
				printls(pde->d_name,depth+4);
			}
			else printf("%*s%s",depth,pde->d_name," ");
	}
	printf("\n");
}

void printlsal(char *dir)
{
	DIR *pdir;
	struct dirent *pde;
	struct stat buf;
	struct passwd *file_own;
	struct group *file_grp;
	struct tm *tm_ptr;
	char prlist[11];
	int i;
	mode_t modes;

	if((pdir=opendir(dir))==NULL){
                fprintf(stderr,"cannot open directory:%s\n",dir);
                return;
        }

	while((pde=readdir(pdir))!=NULL){
		for(i=0;i<10;i++){
			prlist[i]='-';
		}
		prlist[10]='\0';

		stat(pde->d_name,&buf);
		modes=buf.st_mode;
		if(S_ISDIR(modes)) //디렉토리
			prlist[0]='d';
		if(modes & S_IRUSR) //퍼미션...
			prlist[1]='r';
		if(modes & S_IWUSR)
           		prlist[2]='w';
       		if(modes & S_IXUSR)
           		prlist[3]='x';
       		if(modes & 0040)
           		prlist[4]='r';
       		if(modes & 0020)
           		prlist[5]='w';
       		if(modes & 0010)
           		prlist[6]='x';
       		if(modes & 0004)
           		prlist[7]='r';
      		if(modes & 0002)
           		prlist[8]='w';
       		if(modes & 0001)
           		prlist[9]='x';
		file_own=getpwuid(buf.st_uid);
		file_grp=getgrgid(buf.st_gid);
		tm_ptr=gmtime(&buf.st_mtime);

		printf("%s %2ld %5s %5s %5ld %02d월 %02d %d:%02d %-05s\n",prlist,buf.st_nlink,file_own->pw_name,file_grp->gr_name,buf.st_size,tm_ptr->tm_mon+1,tm_ptr->tm_mday,tm_ptr->tm_hour+9,tm_ptr->tm_min,pde->d_name);
	}
}

int main(int argc, char *argv[])
{	
	if(argc==2)
	{
		if(strcmp(argv[1],"-al")==0)
			printlsal(".");
		else
			printf("-al이 아닌것은 구현되지 않았습니다\n");
	}
	else
	{
		printls(".",0);
		return 0;
	}
}
