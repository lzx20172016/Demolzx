#include"../header.h"

int print_tips()
{
    char cwd[2048];
    getcwd(cwd,sizeof(cwd));
    printf("myshell:%s > ",cwd);

}

void handle_cmd(char *cmd)
{

    pid_t pid=fork();
    if(pid==0)
    {
        execlp(cmd,cmd,NULL);
        exit(0);
    }

    wait(NULL);
}
int main(void)
{
    while(1)
    {
        print_tips();

        char cmd[2048];
        fgets(cmd,sizeof(cmd),stdin);
        cmd[strlen(cmd)-1]=0;

        handle_cmd(cmd);
    }
}

