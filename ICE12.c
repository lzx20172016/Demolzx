#include"../header.h"

int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
        sleep(2);
        return 250;//表示子进程结束，但是子进程的PCB不会自动被回收
    }else
    {
       // sleep(1);
       // getchar();//父进程不退出，所以子进程变成了僵尸进程
//      
        int status;
       pid_t pid= wait(&status);
       printf("helloworld\nstatus=%d\n",(int)status);
        
       if(WIFEXITED(status))
       {
            printf("normal exit\n");
            printf("exit is %d\n",WEXITSTATUS(status));
       }
       getchar();
    }

}
