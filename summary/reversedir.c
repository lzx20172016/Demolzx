#include "../header.h"
#include<stdbool.h>
bool IS_FILE(const char *filename)
{

    struct stat buf;
    int ret=stat(filename,&buf);
    if(ret<0)
    {
        printf("open file fails.\n");
        return false;
    }

    if(!(S_ISDIR(buf.st_mode)))
    {
        return true;
    }

}
int handle_file(const char *filename,int fd)
{

    char bufbuf[4096]={0};//保持目录文件信息
    char temp[1024]={0};//用来拼接成文件路径
    struct stat buf;
    int ret=stat(filename,&buf);
    if(ret<0)
    {
        printf("open file fails.\n");
        return -1;
    }

    if(!(S_ISDIR(buf.st_mode)))
    {
        sprintf(bufbuf,"%s\n",filename);
        write(fd,bufbuf,strlen(bufbuf));
        printf("this is not a directory.\n");
        return -1;
    }

    sprintf(bufbuf,"dir\n%s\n",filename);
    write(fd,bufbuf,strlen(bufbuf));

    DIR *dir=opendir(filename);
    struct dirent *pdir=readdir(dir);

    while(1)
    {
        sprintf(temp,"%s/%s",filename,pdir->d_name);
        bool flag=IS_FILE(temp);        
        if(flag)

        {
            write(fd,"file:",5);
            write(fd,temp,strlen(temp));
            write(fd,"\n",1);

        }else
        {

            if((strcmp(pdir->d_name,".")!=0)&&(strcmp(pdir->d_name,"..")!=0))
                handle_file(temp,fd);
        }
        pdir=readdir(dir);
        if(pdir==NULL)
            break;
    }
    return 0;
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("USAGES:%s[filename]\n",argv[0]);
        return -1;
    }
    int fd=open("ab.txt",O_WRONLY|O_CREAT|O_APPEND|O_TRUNC,0777);
    if(fd==0)
    {
        printf("open file fails.\n");
        return -1;
    }
    handle_file(argv[1],fd);
    close(fd);
    return 0;
}
