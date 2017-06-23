#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signal_handle(int a)
{
    if(a==SIGINT)
        printf("signal_handle\n");
    else if(a==SIGABRT)
        printf("abrt\n");
    else if(a==SIGALRM)
        printf("alarm\n");
    else if(a==SIGCHLD)
        printf("child\n");
    else if(a==SIGUSR1)
        printf("usr1 signal\n");
}

int main()
{
    signal(SIGINT,signal_handle);
    signal(SIGABRT,signal_handle);
    signal(SIGALRM,signal_handle);
    signal(SIGCHLD,signal_handle);
    signal(SIGUSR1,signal_handle);
    pid_t pid=fork();
    if(pid==0)
        return 0;




    alarm(1);
    while(1)
    {
        sleep(1);
    }


}
