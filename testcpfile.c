#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//试用文件描述符从指定位置向一个已知文件拷贝数据（覆盖的方式）

int main()
{
    int fd=open("a.txt",O_WRONLY);
    lseek(fd,20,SEEK_SET);
    write(fd,"abcdeg",6);
    close(fd);
    return 0;


}
