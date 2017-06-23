#include"./header.h"
//给出使用dup2函数的范例，将本来应该打印到标准输入输出的信息，打印到指定的文件

int main()
{
    int fd=open("b.txt",O_WRONLY);
    dup2(fd,1);
    close(fd);
    printf("hello world\n");
    return 0;

}
