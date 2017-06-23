
#include"./header.h"
//文件描述符(用户空间);文件描述符对应的下标(内核为进程提供的1024个
//结构体的下标,按“节省原则"分配);文件结构体(内核);文件结构中
//的
//综合使用dup及dup2函数
int main()
{
    int fd=open("a.txt",O_WRONLY);

    int fd_backup=dup(1);//备份标准输出的结构体

    printf("hello ro screen1");
    dup2(fd,1);//拷贝fd所指结构体信息到将标准输出结构体内
    close(fd);

    printf("hello to file\n");

    dup2(fd_backup,1);
    close(fd_backup);
    printf("hello to screen2");
    //printf("fd2:%d\n",fd2);
    return 0;

}
