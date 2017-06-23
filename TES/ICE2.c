#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void handle(int v)
{
    printf("signal int\n");

}
int main()
{
    signal(SIGINT,handle);
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set,NULL);
   // getchar();
    sleep(5);
    printf("remove SIGINT from mask\n");
    sigprocmask(SIG_UNBLOCK,&set,NULL);

    while(1)
    {
        sleep(1);
    }
}
