#include<sys/types.h>
#include<sys/mman.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/mman.h>
#include<utime.h>
#include<dirent.h>
#include<string>
#include<iostream>
using namespace std;


void tar_dir(string srcname,int *pcount)
{
    DIR *dir=opendir(srcname.c_str());//如果是文件不是目录，是否要考虑判断dir是不是NULL
    if(dir==NULL)
        return;
    struct dirent * pdir=readdir(dir);
    while(1)
    {
       
        if(pdir==NULL)
        {
            break;
        }
        if(pdir->d_type==DT_REG)
        {
            (*pcount)++;
        }else if(pdir->d_type==DT_DIR)
        {
            if((strcmp(pdir->d_name,".")!=0)&&((strcmp(pdir->d_name,"..")!=0)))//如果不判断会进入死循环
            {
            tar_dir(srcname+"/"+pdir->d_name,pcount);
            }
        }
        pdir=readdir(dir);
    }
    closedir(dir);
}

int main(int argc,char *argv[])
{

    if(argc<2)
    {
        printf("USAGES:[file1] [file2]\n");
        return -1;
    }
    const char *src_file=argv[1];
    int count=0;
    tar_dir(src_file,&count); 
    printf("count=%d\n",count);
}
