#include"./header.h"
//用open函数创建一个可读可写的a.txt文件，并用dup操作open函数返回的文件描述符//用变量接收dup函数的返回值，再同时向这两个文件描述符写数据，查看能否都能写进a.txt文件,查看两个文件描述符是否相等。

int main()
{
    int fd=open("b.txt",O_RDWR);
    
    int fd2=dup(fd);
    write(fd,"hello",5);
    write(fd2,"world",5);
    printf("fd:%d\n",fd);
    printf("fd2:%d\n",fd2);
    close(fd);

    return 0;

}
