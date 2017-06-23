#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
//证明，被回收的文件描述符，下次使用时不会因为文件描述符值小而不被使用
int main()
{
    int fd1=open("fd.c",O_RDONLY);
    int fd2=open("fd.c",O_RDONLY);
    int fd3=open("fd.c",O_RDONLY);
    printf("fd1:%d\n",fd1);
    printf("fd2:%d\n",fd2);
    printf("fd3:%d\n",fd3);
    close(fd2);

    int fd4=open("fd.c",O_RDONLY);
    printf("fd4:%d",fd4);

    return 0;
}
