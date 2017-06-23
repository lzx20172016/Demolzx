#include"./header.h"
//给出使用stat结构体的实例，并借用stat结构体判断文件是普通的还是目录
int main()
{
    struct stat buf;
    int ret=stat(".",&buf);
    
    if(ret<0)
    {
        printf("stat error\n");
        return 0;
    }

    printf("ino is %d,mode=0x%x\nsize=%d\nblocksize=%d\nblocks=%d\n",(int)buf.st_ino,(int)buf.st_mode,(int)buf.st_size,(int)buf.st_blksize,(int)buf.st_blocks);
    
    if(S_ISREG(buf.st_mode))
    {
        printf("this is normal file\n");
    }else if(S_ISDIR(buf.st_mode))
    {
        printf("this is a directory\n");
    }

    if(S_IRUSR&buf.st_mode)
    {
        printf("user can read\n");
    }
    return 0;


}
