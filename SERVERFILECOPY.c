#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    
    //创建套接字
    int fd=socket(AF_INET,SOCK_STREAM,0);

    //设置结诟体，用来绑定IP和端口
    struct sockaddr_in addr;
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");
    addr.sin_family=AF_INET;
    addr.sin_port=htons(23999);    

    //绑定地址端口信息到socket文件
    bind(fd,(struct sockaddr*)&addr,sizeof(addr));

    //监听
    listen(fd,10);//同时监听10个客户端
    int newfd=accept(fd,NULL,NULL);//创建服务器和客户端之间通信的文件
    if(newfd<0)
    {
        printf("communication fails.\n");
        return;
    }

    

    
    //读客户端的文件信息
    char buf[4096];
    int sum=0;
    int sumw=0;
    int retw=0;
    int ret;
    int lengthargv=0;//用来读传送文件的长度
    while(1)
    {
    
        memset(buf,0,sizeof(buf));
        //读文件名长度
        ret=read(newfd,buf,sizeof(int));
        if(ret<=0)//表示错误和客户端没有多余的文件
            break;
        lengthargv=*(int *)buf;//取长度
        lengthargv=ntohl(lengthargv);//转换成本地的打端小端
        printf("文件名长度是:%d\n",lengthargv);

        //读文件名
        memset(buf,0,sizeof(buf));
        
        ret=read(newfd,buf,lengthargv);
        printf("文件名是:%s\n",buf);
        int fd1=open(buf,O_WRONLY|O_EXCL|O_CREAT,0777);//创建新文件

        //读文件长度
        memset(buf,0,sizeof(buf)); 
        ret=read(newfd,buf,sizeof(int));
        lengthargv=*(int *)buf;
        lengthargv=ntohl(lengthargv);
        printf("文件长度是:%d\n",lengthargv);
        //读文件，写文件
        int readlen=0;
        int sumfile=0;//用来记录读取的文件长度
        while(1)
        {
            memset(buf,0,sizeof(buf));
            readlen=lengthargv>sizeof(buf)?sizeof(buf):lengthargv;
            ret=read(newfd,buf,readlen);
            sumfile+=ret;
            if(ret<=0)
            {
                break;
            }
            write(fd1,buf,ret);   
            if(sumfile==lengthargv)
            {
                break;
            }
        }
        close(fd1);

    }
    return 0;

}
