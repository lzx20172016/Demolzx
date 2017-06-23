#include<signal.h>
#include<stdio.h>
#include<errno.h>
void handle(int v){
    printf("ctrl+c\n");
}
int main()
{
    signal(SIGINT,handle);
    char buf;
    int ret=read(0,buf,sizeof(buf));
    printf("ret=%d\n,errno=%d\n,EINTR=%d\n",ret,errno,EINTR);

}

