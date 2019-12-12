#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

int main(int argc,char *argv[])
{
   DIR *nowdir;
   struct dirent *redir;
   struct stat st;
   struct passwd *file_own;
   struct group *file_grp;
   struct tm *tm_ptr;
   char prlist[11];
   int i;
   mode_t modes;
  
   if(argc==2){
       if((nowdir=opendir(argv[1]))==NULL){
           perror("Directory Open ERROR");
           exit(1);
       }
   }
   else if((nowdir=opendir("."))==NULL){
       perror("Diretory Open ERROR");
       exit(1);
   }
  
   while((redir=readdir(nowdir))!=NULL)
   {

       for(i=0;i<10;i++)
           prlist[i]='-';
       prlist[10]='\0';

       stat(redir->d_name,&st);
       modes=st.st_mode;

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

       file_own=getpwuid(st.st_uid);
       file_grp=getgrgid(st.st_gid);
       tm_ptr=gmtime(&st.st_mtime);

       printf("%s %2d %5s %5s %5d %d-%02d-%02d %d:%02d %-05s\n"
           ,prlist,st.st_nlink,file_own->pw_name,file_grp->gr_name,st.st_size
           ,tm_ptr->tm_year+1900,tm_ptr->tm_mon,tm_ptr->tm_mday,tm_ptr->tm_hour+9,tm_ptr->tm_min
           ,redir->d_name);
   }
}
