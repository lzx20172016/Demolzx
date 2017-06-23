#include "../header.h"


int main()
{

    int ret=write(3,"write xxx",9);
    if(ret<0)
    {
        printf("eror write file\n");
    }
}
