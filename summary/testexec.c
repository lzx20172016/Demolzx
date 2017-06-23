
#include"../header.h"




int main()
{
    printf("hello world\n");
    sleep(3);   
    execl("./a.out","./a.out",NULL);
    return 0;
}
