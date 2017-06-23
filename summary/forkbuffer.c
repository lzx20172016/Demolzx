
#include"../header.h"
//测试子进程保存缓冲区信息，造成打印多次

int main()
{
//    FILE *fp=fopen("a.txt","w+");
  //  char buf[1024]="helloworld\n";
    //fwrite(buf,1,strlen(buf),fp);
    //int pd=open("a.txt",O_WRONLY);
  //  dup2(pd,1);
    printf("hello,world,");
//    int pd=open("a.txt",O_WRONLY);
  //  write(pd,"helloworld",10);
//   sleep(10); 
    int i=0;
    for(i=0;i<5;i++)
    {
        pid_t pid=fork();
//        sleep(3+i*3);
        if(pid==0)
        {
            printf("i=%d",i);
            exit(0);
        }
    
    }
  //  sleep(20);
    for(i=0;i<5;i++)
    {
        wait(NULL);
    }
    printf("parent");
    return 0;

}
