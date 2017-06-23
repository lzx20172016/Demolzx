#include<signal.h>
#include<stdio.h>
#include<errno.h>
//void handle(int v)
//{}
void handle(int v,siginfo_t *info,void *p)
{
    printf("ctrl+c\n");
}
int main()
{
    struct sigaction sig;
    sig.sa_handler=NULL;
    sig.sa_sigaction=handle;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags=0;
    //sig.sa_mask=0;
    sig.sa_flags=SA_RESTART;
    sig.sa_restorer=NULL;
    sigaction(SIGINT,&sig,NULL);
//    getchar();
    char buf;
    int ret=read(0,buf,sizeof(buf));
    printf("ret=%d\n,errno=%d\n,EINTR=%d\n",ret,errno,EINTR);

}

