#include<signal.h>
void child_handle(int v)
{
    while(1)
    {
    int ret=waitpid(-1,NULL,WNOHANG);
    if(ret==-1)
    {
        break;
    }
}

int main()
{
    //wait(NULL);
    signal(SIGCHLD,child_handle);

    pid_t pid=fork();
    if(pid==0)return 0;

    while(1)
    {
        sleep(1);
    }
}
