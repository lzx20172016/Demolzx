#include"../header.h"



int main()
{
    //int ret=execl("./helloworld","./helloworld",NULL);

    int ret=execl("./elloworld","./helloworld",NULL);
    if(ret==0)
    {
        printf("execl success\n");
    }
    else
    {
        printf("execl failure\n");
    }
}



