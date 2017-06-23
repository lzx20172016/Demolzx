#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//本程序用多进程来拷贝文件，思路是先创建并拓展空文件到合适的长度，再用一个父进程的多个子进程按区间拷贝文件，最后由父进程收尾拷贝文件最后的信息
int GetLengthFile(const char * fname)//用文件结构体,结合stat函数获取文件的长度信息
{
    if(NULL==fname)
    {
        return -1;
    }

    struct stat buf;
    int ret=stat(fname,&buf);
    if(ret<0)
    {
        return -1;
    }
    return buf.st_size;
}


void CopyFile(const char *src_file,const char *dst_file,int pos,int LengthFile)
{        
    int fd1=open(src_file,O_RDONLY);
    int fd2=open(dst_file,O_WRONLY);

    lseek(fd1,pos,SEEK_SET);
    lseek(fd2,pos,SEEK_SET);

    //拷贝文件
    char buf[4096];
    while(1)
    {
        #if 0//此处表示错误代码
        memset(buf,0,sizeof(buf));
        int readlength=read(fd1,buf,sizeof(buf));//此处如果LengthFile一开始就小于sizeof（buf）肯定会将文件全部读出，而不按照要读的长度读文件
        printf("readlength:%d\n",readlength);
        write(fd1,buf,readlength);
        LengthFile-=readlength;
        if(LengthFile<=0)
            break;
        #endif
        
#if 1
        memset(buf,0,sizeof(buf));
        int ReadLength=LengthFile>sizeof(buf)?sizeof(buf):LengthFile;
        read(fd1,buf,ReadLength);
        write(fd2,buf,ReadLength);
        LengthFile-=ReadLength;
        if(LengthFile<=0)
        {
            break;
        }
#endif
    }
    close(fd1);
    close(fd2);
}
int main(int argc,char *argv[])
{
    if(argc<4)//排除缺省的命令
    {
        printf("argument error.\n");
        return -1;
    }

    if(strcmp(argv[1],"-cp")!=0)
    {
        printf("this is not the order for cpfile.\n");
        return -1; 
    }

    int pscount=atoi(argv[2]);
    if(pscount<=0)
    {
        printf("give me a process.\n");
        return -1;
    }

    const char *src_file=argv[3];
    const char *dst_file=argv[4];

    //获得文件长度
    int FileLen=GetLengthFile(src_file);
    if(FileLen<0)
    {
        printf("stat faile.\n");
        return -1;
    }

    //创建并拓展新文件
    int fd=open(dst_file,O_CREAT|O_RDWR,0777);
    if(fd<0)
    {
        printf("creat new file fails.\n");
        return -1;
    }

    ftruncate(fd,FileLen);
    close(fd);
    
    //根据文件长度以及进程个数决定每个子进程要拷贝的文件长度
    int SubPsFileLen=FileLen/pscount;//注意pscount包括了父进程，是个总数

    int i=0;

    for(;i<pscount-1;i++)
    {
        printf("i=%d\n",i);
        pid_t pid=fork();
        if(pid==0)//注意父进程和子进程都会调用fork函数，父进程能执行返回大于零的数，子进程不能返回零
        {
            CopyFile(src_file,dst_file,i*SubPsFileLen,SubPsFileLen);//源文件名(带路径)、目的文件名带路径、从源文件拷贝的起点、拷贝文件的长度
            return 0;
        }
    }
#if 1
    int pos=(pscount-1)*SubPsFileLen;
    CopyFile(src_file,dst_file,pos,FileLen-pos);
#endif
    #if 0
    //父进程最后收尾
    sleep(3);    
    int fd1=open(src_file,O_RDONLY);
    int fd2=open(dst_file,O_WRONLY);

    lseek(fd1,(pscount-1)*SubPsFileLen,SEEK_SET);
    lseek(fd2,(pscount-1)*SubPsFileLen,SEEK_SET);

    //拷贝文件
    char buf[4096];
    int LengthFile=FileLen-(pscount-1)*SubPsFileLen;
    while(1)
    {
        memset(buf,0,sizeof(buf));
        int readlength=read(fd1,buf,sizeof(buf));
        printf("buf=%s\n",buf);
        write(fd2,buf,readlength);
        LengthFile-=readlength;
        if(LengthFile<=0)
            break;
    }
    close(fd1);
    close(fd2);
    #endif  
   for(i=0;i<pscount-1;i++)//防止内存泄漏
    {
        wait(NULL);
    }
    return 0;
}
