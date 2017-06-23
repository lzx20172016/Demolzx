
#include"./header.h"
//给出实例，证明dup2函数的返回值与哪个文件描述符相同
int main()
{
    int fd=open("a.txt",O_RDWR);

    int fd2=dup2(fd,5);


    printf("fd2:%d\n",fd2);
    return 0;

}
