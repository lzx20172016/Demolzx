#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handle(int v)
{
    printf("sigint\n");
}


int main()
{
    signal(SIGINT,handle);
//    getchar();
    char buf;
    read(0,&buf,1);
}
