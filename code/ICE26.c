#include"../header.h"
#include<stdarg.h>
#if 0
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
#endif

void mylog(const char * file,int line,const char *fmt,...)
{
    char buf[2048];
    va_list ap;
    va_start(ap,fmt);

    vsprintf(buf,fmt,ap);
    va_end(ap);
    printf("[%s:%d]:%s",file,line,buf);
}

int main()
{
    mylog(__FILE__,__LINE__,"这里有错误\n");

}
