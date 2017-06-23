#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
//用程序证明一个进程最大可打开的文件是1024个，包括了标准输出输入和出错

int main()
{
    for(int i=0;;++i)
    {
        int fd=open("fd.c",O_RDONLY);
        if(fd<0)
        {
            printf("open error i is %d\n",i);//i最后只读了1021次，因为有3个文件爱你描述如是给标准输入输出以及错误的
            break;
        }
        else
        {
            printf("fd is %d\n",fd);

        }
    }

}
