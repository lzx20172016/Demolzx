#include "../header.h"

int main()
{
#if 0
    char *a="   kk    ";
    char *tmp=strtok(a,"");
    tmp=strtok(NULL,"");
    printf("tmp:%s\n",tmp);
    return 0;
#endif
#if 0
char a[100]="   kk    ";
char *tmp=strtok(a," ");
//tmp=strtok(NULL,"");
printf("tmp:%s\n",tmp);
printf("%d\n",*(tmp+4));
#endif

char a[20]="   kk  kk   ";
//memset(a,0,sizeof(a));
char *tmp=strtok(a," ");
strtok(NULL," ");
strtok(NULL," ");
printf("temp=(%s)\n",tmp);
printf("a=(%s)\n",a);
int i=0;
while(1)
{
    printf("%d ",a[i]);
    i++;
    if(i==20)
        break;
}
return 0;


}





