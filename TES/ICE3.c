#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void handle(int v)
{
    printf("hahahhaha\n");

}
int main()
{
    signal(34,handle);
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,34);
    sigprocmask(SIG_BLOCK,&set,NULL);
    
    kill(getpid(),34);
    kill(getpid(),34);
    kill(getpid(),34);
    kill(getpid(),34);
    kill(getpid(),34);




   // getchar();
    sleep(5);
    printf("remove 34 from mask\n");
    sigprocmask(SIG_UNBLOCK,&set,NULL);

    while(1)
    {
        sleep(1);
    }
}
