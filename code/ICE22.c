#include "../header.h"

int main()
{

    pid_t pid=fork();

    if(pid==0)
    {
        setpgid(getpid(),getpid());
       pid_t pid=fork();
        if(pid==0)
        {
            
        }
    }
    int ch= getchar();
    printf("%c\n",ch);
}
