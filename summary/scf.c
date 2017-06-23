#include"../header.h"



int main()
{
    char buf[1024]={0};
//    scanf("%s",buf);
    fgets(buf,sizeof(buf),stdin);
    printf("buf=%s\n",buf);
    return 0;
}
