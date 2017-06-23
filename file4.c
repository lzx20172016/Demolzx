#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//获得普通文件爱你的文件描述符的开始值
int main()
{
//    int fd=open("a.tmp",O_WRONLY|O_CREAT,0777);
   int fd=open("a.txt",O_WRONLY|O_TRUNC);//阶段文件

    printf("fd is %d\n",fd);

    return 0;



}
