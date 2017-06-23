#include"./header.h"

//使用fcntl函数为已经确定了open权限的文件追加文件权限

int main()
{
   // int fd=open("a.txt",O_WRONLY|O_CREAT|O_EXCL,0777);//这种方式不恩那个实现功能

    int fd=open("a.txt",O_WRONLY);
    int fd1=open("a.txt",O_WRONLY);
    // int fd2=open("a.txt
   //
    int flag;
    flag=fcntl(fd,F_GETFL);
    flag|=O_APPEND;

    fcntl(fd,F_SETFL,flag);

    flag=0;
    flag=fcntl(fd1,F_GETFL);
    flag|=O_APPEND;
    fcntl(fd1,F_SETFL,flag);
    write(fd,"hello",5);
    printf("fd worlds");
    write(fd1,"world",5);

}





