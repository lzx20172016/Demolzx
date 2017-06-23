#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

int FileLen;
char *srcfile;
char *dstfile;

int endfile;
int posfile;
pthread_mutex_t mutex;
int SubPsFileLen;
int GetLengthFile(const char * fname)
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
        
#if 1
        memset(buf,0,sizeof(buf));

        int ReadLength=LengthFile>sizeof(buf)?sizeof(buf):LengthFile;
        read(fd1,buf,ReadLength);
        printf("buf=%s\n",buf);
        write(fd2,buf,ReadLength);
        LengthFile-=ReadLength;
        if(LengthFile<=0)
        {
            break;
        }
#endif
    }
    printf("LengthFile=%d\n",LengthFile);
    close(fd1);
    close(fd2);
}
#if 0
void *thread_func(void *ptr)
{
    CopyFile(srcfile,dstfile,0,FileLen);
    printf("copyfile\n");

}
#endif

#if 1
void *thread_func(void *ptr)
{
    pthread_mutex_lock(&mutex);
    posfile=endfile;
    endfile+=SubPsFileLen;
    pthread_mutex_unlock(&mutex);
    CopyFile(srcfile,dstfile,posfile,endfile);
    pthread_exit(0);
}
#endif

int main(int argc,char *argv[])
{
    pthread_mutex_init(&mutex,NULL);
    
    if(argc!=4)//排除缺省的命令
    {
        printf("argument error.\n");
        return -1;
    }


    int pscount=atoi(argv[1]);
    if(pscount<=0)
    {
        printf("give mumber of thread.\n");
        return -1;
    }

    srcfile=argv[2];
    dstfile=argv[3];

    //获得文件长度
    FileLen=GetLengthFile(srcfile);
    if(FileLen<0)
    {
        printf("stat faile.\n");
        return -1;
    }

    //创建并拓展新文件
    int fd=open(dstfile,O_CREAT|O_RDWR|O_EXCL,0777);
    if(fd<0)
    {
        printf("creat new file fails.\n");
        return -1;
    }

    ftruncate(fd,FileLen);
    close(fd);
    
    int SubPsFileLen=FileLen/pscount;

    int i=0;
    posfile=0;
    endfile=0;

    pthread_t *tid=(pthread_t *)malloc((pscount-1)*sizeof(pthread_t));
    for(i=0;i<pscount-1;i++)
    {

    pthread_create(tid+i,NULL,thread_func,NULL);
    }
#if 0
    pthread_t tid;

    pthread_create(&tid,NULL,thread_func,NULL);

    void *ret;
    pthread_join(tid,&ret);
    pthread_exit(0);
#endif

    posfile=endfile;
    CopyFile(srcfile,dstfile,posfile,FileLen);
    
    for(i=0;i<pscount-1;i++)
    {
        void *ret;
        pthread_join(tid[i],&ret);
    }
    pthread_exit(0);
}
