
#include"../header.h"


int main()
{

    pid_t pid=fork();
    if(pid==0)
    {

        int fd=open("b.txt",O_WRONLY);//注意b.txt文件必须存在
        printf("fd=%d\n",fd);
//        sleep(1);
        // execlp("./writefile","./writefile",NULL);
        execlp("./2","./2",NULL);
        printf("error start program\n");
        return 0;
    }
    sleep(2);
    //close(fd);
    wait(NULL);
    printf("chile program end\n");
}
