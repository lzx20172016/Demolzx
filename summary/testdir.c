#include"../header.h"



int main(int argc,char *argv[])
{
    if(argc<2)
    {
        return -1;
    }

    struct stat buf;
    int ret=stat(argv[1],&buf);
    if(ret<0)
    {
        printf("open file fails.\n");
        return -1;
    }

    if(!S_ISDIR(buf.st_mode))
    {
        printf("this is not a directory.\n");
        return -2;
    }

    DIR *dir=opendir(argv[1]);
    struct dirent *pdir=readdir(dir);

    while(1)
    {
        if(pdir==NULL)
            {
                break;
            }
        printf("%s\n",pdir->d_name);
        pdir=readdir(dir);
    }
    return 0;
}
