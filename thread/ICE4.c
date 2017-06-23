#include<stdio.h>

#include<pthread.h>

int global_var=0;

void foo()
{
   pthread_t tid= pthread_self();
   printf("tid:%d\n",(int)tid);
}
void *thread_func(void *p)
{
    printf("hello thread\n");
    global_var=100;
    foo();
    return 0;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread_func,NULL);
    pthread_create(&tid,NULL,thread_func,NULL);
    sleep(1);
    foo();    
    printf("global_var=%d\n",global_var);
}
