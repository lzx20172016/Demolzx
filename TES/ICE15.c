#include<signal.h>
#include<stdio.h>



int main()
{
    char *p=malloc(100);
    union sigval v;
   // v.sival_int=98;
    v.sival_ptr=p;
    sigqueue(3469,SIGINT,v);

    getchar();


}
