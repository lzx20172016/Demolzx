#include"./header.h"

//是哟给你fcntl函数为已经打开的读写文件权限的文件描述符追加权限

int main()
{
   // int fd=open("a.txt",O_WRONLY|O_CREAT|O_EXCL,0777);//这种方式不恩那个实现功能

    int fd=open("a.txt",O_WRONLY);
//    int fd1=open("a.txt",O_WRONLY);
     int fd2=dup(fd);
   //
    int flag;
    flag=fcntl(fd,F_GETFL);
    flag|=O_APPEND;

    fcntl(fd,F_SETFL,flag);

    flag=fcntl(fd2,F_GETFL);
    if(flag&O_APPEND)
    {
        printf("has O_APPEND\n");
    }
    else
    {
        printf("no O_APPEND\n");
    }
   // write(fd,"hello",5);
   // printf("fd worlds");
    //write(fd1,"world",5);

}





