

#include"../header.h"

int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
    setsid();
    sleep(1000);
    //getchar();//此处不能用getchar（）代替sleep，因为getchar作用与会话，建立了一对一的联系，但是独立过后，子进程已经不属于本会话，所以是不会接收到这个终端上的任何人输入的信息
    }
}


