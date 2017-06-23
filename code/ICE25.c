#include"../header.h"
#include<stdarg.h>

int add(int count,int a,int b,...)
{
    int c=a+b;
    va_list ap;
    va_start(ap,b);
    int i;
    for(i=0;i<count;i++)
    {
        int arg=va_arg(ap,int);
        c+=arg;
    }
    va_end(ap);
    return c;
}

int main()
{
    int c=add(1,2,3,4);
    printf("%d\n",c);
}
