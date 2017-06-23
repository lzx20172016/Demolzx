#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void *thread_func(void *p1)
{
//    getchar();
    char *p=strdup("ret value");
    printf("hello thread\n");

    return p;
}
int main()
{
    pthread_t tid;

    pthread_create(&tid,NULL,thread_func,NULL);
    void *ret;
    pthread_join(tid,&ret);
    printf("%s\n",(char *)ret);
    return 0;
    

}
