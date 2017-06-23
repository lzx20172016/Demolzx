#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

//本程序模拟客户端和服务器之间的通信，客户端将两个以上文件传送给服务器
//客户端和服务器端模拟通信的报文传送方式是文件名长度、文件名、文件长度、文件内容

int main(int argc,char **argv)
{
    if(argc<2)
    {
        printf("USAGE:[FILE1][FILE2]\n");
        return -1;
    }
    //建立socket文件
    int cl=socket(AF_INET,SOCK_STREAM,0);

    //建立绑定套接字的地址
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(23999);

    //连接socket文件和套接字
    if(connect(cl,(struct sockaddr*)&addr,sizeof(addr))==-1)
    {
        perror("connect");
    }
    int i=1;
    while(1)
    {
        if(i==argc)
        {
            break;
        }
        int fd=open(argv[i],O_RDONLY);
        if(fd==-1)
        {
            perror("read:");
            return -1;
        }
        char buf[4096];
        int sumw=0;
        int sum=0;
        int ret;
        int lengthargv;
        //客户端传送文件的格式是
        //文件名长度|文件名|文件长度|文件内容；这是客户端和服务器端约定好的
        //这种约定方式是最简单的，如果用结构体还必须考虑传送结构体的长度大小。
        //传送文件名长度注意发送段的长度是整型，可能不是大端对齐
        lengthargv=strlen(argv[i]);
        printf("lengthargv:%d\n",lengthargv);
        lengthargv=htonl(lengthargv);
        write(cl,(char *)&lengthargv,sizeof(int));

        //传送文件名
        write(cl,argv[i],strlen(argv[i]));


        //获得文件的长度
        struct stat statbuf;
        stat(argv[i],&statbuf);
        lengthargv=(int)statbuf.st_size;
        
        printf("lengthargv:%d\n",lengthargv);
        lengthargv=htonl(lengthargv);
        //将lengthargv用字符传送的方式发送给对方
        write(cl,(char *)&lengthargv,sizeof(int));//注意此时没有大段和小端的区别
        
        while(1)
        {
            
            ret=0;
            memset(buf,0,4096);
            ret=read(fd,buf,sizeof(buf));
            printf("read ret=%d\n",(int)ret);
            sum+=ret;
            printf("client sum=%d\n",sum);
            if(ret<=0)//此处没有考虑到打断ENINT问题
            {
                break;
            }
            ret=write(cl,buf,ret);

            {
                sumw+=ret;
                printf("client sumw=%d\n",sumw);
            }
        }
        i++;
    }
    return 0;
}
