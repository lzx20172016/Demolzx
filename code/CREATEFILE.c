
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//用来拓展文件的函数的使用
int main()
{
    int fd=open("mm.txt",O_CREAT|O_WRONLY,0777);

#if 0
//    truncate(fd,2);//注仪truncate的参数是文件路径名；ftruncate是文件描述符
    ftruncate(fd,1000);
    close(fd);
#endif
    truncate("mm.txt",100);
    return 0;
}
