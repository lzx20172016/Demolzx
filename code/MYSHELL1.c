
#include"../header.h"

char g_cmd[4096];

char *g_cmdargs[1024];
int g_args_count=0;

#define PATH_TYPE_A 0
#define PATH_TYPE_R 1
#define PATH_TYPE_C 2

int path_type(char *cmd)
{
    char *slas_pos=strstr(cmd,"/");
    if(slas_pos==cmd)
    {
        return PATH_TYPE_A;
    }
    else if(slas_pos!=NULL)
    {
        return PATH_TYPE_R;
    }

    return PATH_TYPE_C;

}

void get_cmd()
{
    char cur_path[1024];
    printf("%s$",getcwd(cur_path,sizeof(cur_path)));

    fgets(g_cmd,sizeof(g_cmd),stdin);

    g_cmd[strlen(g_cmd)-1]=0;
}

void split_cmd()
{
    g_args_count=0;
    char *arg=strtok(g_cmd,"\t");
    while(1)
    {
        g_cmdargs[g_args_count++]=arg;
        if(arg==NULL)
            break;
        arg=strtok(NULL,"\t");
    }
}


void handle_cmd()
{
    split_cmd();

    if(strcmp(g_cmdargs[0],"cd")==0)
    {
        if(g_cmdargs[1]!=NULL)
            chdir(g_cmdargs[1]);
        else
            chdir(getenv("HOME"));
        return;
    }

    pid_t pid=fork();
    if(pid==0)
    {
        setpgid(0,0);
        int ret=execvp(g_cmdargs[0],g_cmdargs);
        if(ret<0)
        {
            exit(1);
        }

        return;
    }
    
        wait(NULL);
}

int main()
{
    while(1)
    {
        get_cmd();
        if(strlen(g_cmd)==0)
            continue;
        
        handle_cmd();

    }
}
































