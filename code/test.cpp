#include"./header.h"
//设计程序打印出目录和文件信息
int main(int argc,char **argv)
{
    if(argc<2)
    {
        printf("need more arguments\n");
        return 0;
    }
    const char *src=argv[1];
    struct stat buf;
    int ret=stat(src,&buf);
    if(IS_ISREG(buf.st_mode))
    {
        printf("this is a regular file\n");
        printf("inode:%d\n",buf.st_ino);
    }else if(IS_ISDIR(buf.st_mode))
    {
    DIR *dir=opendir(src);
    printf("opendir works\n");
    if(dir==NULL)
    {
        printf("opendir fails\n");
        return 0;
    }
    struct dirent *pdir=readdir(dir);
    if(pdir==NULL)
    {
        printf("pdir open wrong\n");
        return 0;
    }
    printf("id:%d\n,name=%s\n",(int)pdir->d_ino,pdir->d_name);
    }
    return 0;
}





