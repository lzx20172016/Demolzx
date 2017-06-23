#include"../header.h"

int print_tips()
{
    char cwd[2048];
    getcwd(cwd,sizeof(cwd));
    printf("myshell:%s > ",cwd);

}

int handle_builtin_cmd(char *cmd1)
{   
    char *cmd=strdup(cmd1);
    char *c=strtok(cmd," \t");
    int ret;
    if(strcmp(c,"cd")==0)
    {
       ret=1;
        char *path=strtok(NULL," \t");
        chdir(path);
    }

    
    free(cmd);
    return ret;

}

void handle_cmd(char *cmd)
{
    int isAppend=0;
    if(strstr(cmd,">>"))isAppend=1;
    char *cmd1=strtok(cmd,">");
    char *filename=strtok(NULL,">");
    filename=strtok(filename," \t");
    printf("****%s****\n",filename);

    char *args[250];
    int i=0;

    char *c=strtok(cmd1," \t");
    args[i++]=c;

    while(1)
    {
        char *arg=strtok(NULL," \t");
        args[i++]=arg;
        if(arg==NULL)break;
    }

    pid_t pid=fork();
    if(pid==0)
    {
        if(filename)
        {
            int flag;
            if(isAppend)
                flag=O_WRONLY|O_APPEND|O_CREAT;
            else
                flag=O_WRONLY|O_TRUNC|O_CREAT;
        int fd=open(filename,flag,0777);
        dup2(fd,1);
        close(fd);
        }
        execvp(c,args);
        exit(0);

    }
    wait(NULL);




}
void 
int main(void)
{
    while(1)
    {
        print_tips();

        char cmd[2048];
        fgets(cmd,sizeof(cmd),stdin);
        cmd[strlen(cmd)-1]=0;
        
        if(!handle_builtin_cmd(cmd))
        handle_cmd(cmd);
    }
}

