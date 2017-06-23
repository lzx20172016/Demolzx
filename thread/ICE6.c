#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void *thread_func(void *p)
{
    getchar();
    return NULL;
}
int main()
{
    pthread_t tid;

    pthread_create(&tid,NULL,thread_func,NULL);
    pthread_exit(0);
    exit(0);
    return 0;

}
