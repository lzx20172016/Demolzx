#include"../header.h"
#include<stdarg.h>

//不定参数函数
void _mylog(const char * file,int line,const char *fmt,...)//fmt的作用相当与哨兵
{
    char buf[2048];
    va_list ap;
    va_start(ap,fmt);

    vsprintf(buf,fmt,ap);
    va_end(ap);
    printf("[%s:%d]:%s",file,line,buf);
}

//不定参数宏
#define mylog(fmt,...) _mylog(__FILE__,__LINE__,fmt,##__VA_ARGS__)//其中vaargs才与调用中的“这里有错误”对应


int main()
{
//    mylog("这里有错误\n");
    mylog("a is %d\n",100);
}
