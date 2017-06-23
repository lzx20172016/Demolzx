#include"../header.h"
//由于父进程的文件描述符的1号内的指针指向一个自定义的文本文件，造成所有printf命令都打印到了这个文件，造成看起来像是进入了阻塞状态；实际上只要在子进程中
//修改1号文件描述符即可
void Creat_Env()
{
    //用当前路径名作为shell的开始
    char path[1024];
    getcwd(path,sizeof(path));
    printf("myshell@%s >> ",path);

}
#if 0 //"ls"命令/*{{{*//*{{{*//*{{{*/
void ls_shell(const char *cmd)
{
    if(cmd==NULL)
        return;
    pid_t pd=fork();
    if(pd==0)
    {
        execlp(cmd,cmd,NULL);/*}}}*/


        exit(0);
        }
wait(NULL);//无论execl执行成功与否，本程序句都能回收子进程

}

#endif
/*}}}*//*}}}*/
#if 0/*{{{*/
//" ls "命令
void ls_shell(char *cmd)
{
    if(cmd==NULL)
        return;
    char *tmp=strtok(cmd," \t");

    pid_t pd=fork();
    if(pd==0)
    {
        execlp(tmp,tmp,NULL);
        exit(0);
    }
    wait(NULL);//无论execl执行成功与否，本程序句都能回收子进程

}
#endif/*}}}*/

//" ls -al"命令,消除空格
//实现重定向功能ls > a.txt
void ls_shell(char *cmd)
{
    if(cmd==NULL)
        return;
    char *args[50];
    char *tmp=strtok(cmd," \t");
    char *pstart=tmp;
    int i=0;
    args[i++]=tmp;


    while(1)
    {
        tmp=strtok(NULL," \t");
        args[i++]=tmp;//保证args中存在NULL哨兵，防止函数execvp不知道第二个参数何时结束
        if(tmp==NULL)
            break;
    }
    //printf("args[0]=%s\n",args[0]);
    //    printf("args[1]=%s\n",args[1]);
    //  printf("args[2]=%s\n",args[2]);
    if((args[1]!=NULL)&&(strstr(args[1],">")!=NULL)&&(args[2]!=NULL))//如果存在重定向指令，就将信息打印到自定义文件，用dup2改变文件描述符指针
    {
        int fd=open(args[2],O_WRONLY|O_CREAT|O_TRUNC,0777);
        dup2(fd,1);
        pid_t pd=fork();
        if(pd==0)
        {
            // execl(pstart,pstart,NULL);//execl第一个参数必须是路径名
//            execlp(pstart,pstart,NULL);//execlp第一个参数是命令名
            printf("fork works\n");
            exit(0);
        }
        printf("execlp works\n");
    }else
    {
        pid_t pd=fork();
        if(pd==0)
        {
            execvp(pstart,args);
            exit(0);
        }
        printf("execvp\n");
    }

    printf("-----wait----\n");
    //wait(NULL);//无论execl执行成功与否，本程序句都能回收子进程
    printf("----wait----\n");
    return ;
}
int main()
{

    while(1)
    {
        //搭建shell环境
        Creat_Env();        
        //输入命令
        char cmd[1024];
        fgets(cmd,sizeof(cmd),stdin);
        cmd[strlen(cmd)-1]=0;//将换行字符变成\0
        ls_shell(cmd);
    }
    return 0;
}
