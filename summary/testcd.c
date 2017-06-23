#include "../header.h"


int main()
{
    while(1)
    {
    char buf[100]="/home/lzx/";
    char *path=getenv("HOME");
    int ret=chdir(path);
    execlp("ls","ls",NULL);
    printf("ret:%d\n",ret);
    getchar();
    }
    return 0;

}
