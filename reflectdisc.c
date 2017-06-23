#include"./header.h"
//给出磁盘的内存映射的使用方法
int main()
{
    void *addr=NULL;
    size_t length=4096;
    int prot=PROT_READ|PROT_WRITE;//protect
    //int flags=MAP_SHARED;
    int flags=MAP_PRIVATE;//改成私有的以后是不能成功打印的
    int fd=open("a.txt",O_RDWR);    
    off_t offset=0;
    char *ptr=(char *)mmap(
            addr,
            length,
            prot,
            flags,
            fd,
            offset);
    strcpy(ptr,"hello shenzhen");
    strcpy(ptr,"******");
    munmap(ptr,length);
    close(fd);
}

