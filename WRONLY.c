#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//给出用open函数写新文件的程序
int main()
{



    int ret=open("a.txt",O_WRONLY|O_CREAT,0775);
   // int ret=open("a.txt",O_WRONLY|O_EXCL);
    //int ret=open("a.txt",O_WRONLY|O_TRUNC);
    if(ret<0)
    {
    //    perror("open fail");
        printf("open fail");
        return -1;
    }
    write(ret,"hello",3);
   close();
    return 0;
}
