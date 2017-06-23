#include"../header.h"

int print_tips()
{
    char cwd[2048];
    getcwd(cwd,sizeof(cwd));
    printf("myshell:%s > ",cwd);

}
    
int main(void)
{
    while(1)
    {
        print_tips();

        char cmd[2048];
        fgets(cmd,sizeof(cmd),stdin);

        printf("---%s-----\n",cmd);
    }
}

