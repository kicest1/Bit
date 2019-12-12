#include<stdio.h>
#include<sys/vfs.h>

void getSpace(char *path){
    struct statfs rootfs;
    if(statfs("/",&rootfs) == -1){
        printf("statfs error\n");
    }
    printf("block %ld\n", rootfs.f_blocks*(rootfs.f_bsize/1024));
    printf("avail %ld\n", rootfs.f_bavail*(rootfs.f_bsize/1024));
}


int main(void){
    getSpace("/");
    return 0;
}
