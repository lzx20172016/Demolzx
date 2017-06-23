#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
//使用open和read函数读文件，并打印出文件信息
int main()
{
    int fd=open("/dev/input/mouse0",O_RDONLY);

    if(fd<0)
    {
        perror("open");
        return 0;
    }

    while(1)
    {
        char buf[8];

        int ret=read(fd,buf,sizeof(buf));

        printf("ret is %d\n",ret);
    };
    return 0;
}

