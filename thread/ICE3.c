#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
char buf[1024];
int ret;
int main()
{
    int fd_mice=open("/dev/input/mice",O_RDONLY);
    if(fd_mice<0)
    {
        perror("open mice");
        return 0;
    }
    int fd_key=open("/dev/input/event1",O_RDONLY);
    
    if(fd_key<0)
    {
        perror("open key");
        return 0;
    }
    
    pid_t pid=fork();
    if(pid==0)
    {

        while(1)
        {

        //char buf[1024];
     ret= read(fd_mice,buf,sizeof(buf));
       if(ret>0)
       {
        printf("read mice info\n,ret=%d\n",ret);
       }
       else if(ret<0)
       {
           printf("read mice info error,errno=%d\n",errno);
       }
        }
        return 0;
    }


    while(1)
    {
       // char buf[1024];
       // int ret;
        ret= read(fd_key,buf,sizeof(buf));
       if(ret>0)
       {
        printf("read key info\n,ret=%d\n",ret);
       }
       else if(ret<0)
       {
           printf("read key info error,errno=%d\n",errno);
       }
//       return 0;
    }
    return 0;
}
