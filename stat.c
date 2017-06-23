#include<sys/stat.h>
#include<stdio.h>

int main()
{
    struct stat buf;
    stat("dir2/file2",&buf);

    printf("%d\n",(int)buf.st_ino);
}

