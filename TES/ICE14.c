#include<signal.h>
#include<stdio.h>
void handle(int v,siginfo_t *info,void *p)
{
    //printf("recv SIGINT,arg=%d\n",(int)info->si_value.sival_int);
    printf("recv SIGINT,arg=%d\n",(int)info->si_int);
}


int main()
{
    struct sigaction act;
    act.sa_handler=NULL;
    act.sa_sigaction=handle;
    sigemptyset(&act.sa_mask);
    act.sa_flags=SA_SIGINFO|SA_RESTART;
    act.sa_restorer=NULL;

    sigaction(SIGINT,&act,NULL);

    union sigval v;
    v.sival_int=100;
    
    sigqueue(getpid(),SIGINT,v);
    
    getchar();
}
