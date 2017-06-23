#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

char buf[1024];
void handle_data()
{
    printf("usre input is %s\n",buf);
}

void handle_chid1(int v)
{
    while(1)
    {
        int ret=waitpid(-1,NULL,WNOHANG);
        if(ret<0)break;
    }
}

void handle_chid(int v,siginfo_t*info,void *p)
{
    handle_chid1(v);
}
int main()
{
//    signal(SIGCHLD,handle_chid);
    struct sigaction act;
    act.sa_handler=NULL;
    act.sa_sigaction=handle_chid;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    act.sa_restorer=NULL;
    sigaction(SIGCHLD,&act,NULL);
    while(1)
    {
//        char *ret=fgets(buf,sizeof(buf),stdin);
  //      if(ret==NULL)break;
        int ret=read(0,buf,sizeof(buf));
        if(ret<0)
            break;
        pid_t pid=fork();
        if(pid==0)
        {
            handle_data();
            exit(0);
        }
    }
}
