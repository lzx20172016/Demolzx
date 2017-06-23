#include<sys/stat.h>
#include<stdio.h>
//通过struct stat结构体定义变量，使用stat函数获得目录下某个文件的信息，并打印出文件的inode值
int main()
{
    struct stat buf;

    stat("dir2/abc",&buf);
    printf("%d\n",(int)buf.st_ino);
}
