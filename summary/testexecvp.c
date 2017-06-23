#include"../header.h"



int main()
{
    char buf[100]=" ls -al";
    char *args[5];
    int i=0;
    char *tmp=strtok(buf," ");
    char *p=tmp;
    args[i++]=tmp;
    printf("tmp=%s\n",tmp);
    while(1)
    {
            tmp=strtok(NULL," ");
            if(tmp==NULL)
                break;
            
            args[i++]=tmp;
    }
    //execvp(buf,args);本句是无法执行的，因为buf前的空格并不能切除,造成buf字符串不是一个可执行程序的名字
    execvp(p,args);//p所指向的字符串是可执行程序的名字
    return 0;
}


