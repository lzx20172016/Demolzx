#include"./header.h"

//


int main()
{
    int fd=open("a.txt",O_RDONLY);
    getchar();

    char buf[1024]={0};

    read(fd,buf,sizeof(buf));

    printf("%s\n",buf);
    close(fd);

}
