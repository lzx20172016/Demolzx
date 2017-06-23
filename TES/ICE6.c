#include<signal.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
    signal(SIGINT,SIG_IGN);
    while(1)
    {
        sleep(1);
    }

}
