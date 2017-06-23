#include<stdio.h>

#include<pthread.h>

void *thread_func(void *p)
{

    return NULL;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread_func,NULL);
    printf("tid=%d\n",(int)tid);
    pthread_create(&tid,NULL,thread_func,NULL);
    printf("tid=%d\n",(int)tid);

    pthread_create(&tid,NULL,thread_func,NULL);

    printf("tid=%d\n",(int)tid);
    getchar();
}

