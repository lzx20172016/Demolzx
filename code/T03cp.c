#include "./header.h"

int main(int argc,char *argv[])
{
    const char *src_filename=argv[1];
    const char *dst_filename=argv[2];

    FILE *fp_src=fopen(src_filename,"r");
    if(fp_src==NULL)
    {
        perror("fopen");
        return 1;
    }

    FILE *fp_dst=fopen(dst_filename,"w");
    if(fp_dst==NULL)
    {
        perror("open");
        return 2;
    }

    char buf[4096];
    while(1)
    {
        int ret=fread(buf,1,4096,fp_src);
        if(ret<=0)break;
        
        fwrite(buf,ret,1,fp_dst);
    }
    struct stat stat_buf;
    stat(src_filename,&buf);
    
    struct timeval tv[2];
    tv[0].tv_sec=stat_buf.st_atime;
    tv[0].tv_usec=0;
    
    tv[1].tv_sec=stat_buf.st_mtime;
    tv[1].tv_usec=0;
    
    utimes(dst_filename,tv);








}
