#include"./header.h"
#include<utime.h>
int main()
{
    const char *path="dir2/file2";

//    chmod(path,S_ISUID|S_IRUSR);

    //int ret=access(path,R_OK);
   // if(ret==0)
   // {
     //   printf("可读");
   // }
//    link(path,"dir2/file2-link");
  //  symlink(path,"dir2/file2-symlink");
    chown(path,0,0);
    struct utimbuf buf;
    buf.actime=0;
    buf.modtime=0;
    utime(path,&buf);

    struct timeval tv[2];
    tv[0].tv_sec=0;
    tv[0].tv_usec=1;
    tv[1].tv_sec=0;
    tv[1].tv_usec=1000;

    utimes(path,tv);
}
