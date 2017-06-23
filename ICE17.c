#include"../header.h"



int main()
{
    //int ret=execl("./helloworld","./helloworld",NULL);
    int fd=open("a.txt",O_WRONLY);
    int ret=execl("./writefile","./writefile",NULL);
    if(ret==0)
    {
        printf("execl success\n");
    }
    else
    {
        printf("execl failure\n");
    }
}



