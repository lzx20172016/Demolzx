#include<signal.h>
#include<stdio.h>

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
    sig.sa_restorer=NULL;
    sigaction(SIGINT,&sig,NULL);

    while(1)
    {
        sleep(1);
    }
}

