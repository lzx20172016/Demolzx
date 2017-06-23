#include"../header.h"
//使用open函数将内存数据写入磁盘

struct student
{
    char *name;
    int score;
    int age;
//    int len;
};


int main()
{
    char buf[2048];
    int len;

    struct student s;
    printf("please input name:");
    fgets(buf,sizeof(buf),stdin);

    len=strlen(buf);
    buf[len-1]=0;

    s.name=strdup(buf);

#if 0
    int len=strlen(buf);
    s.name=malloc(len);
    memset(s.name,0,len);
    memcpy(s.name,buf,len-1);
#endif
        



    printf("please input age:");
    fgets(buf,sizeof(buf),stdin);
    len=strlen(buf);
    buf[len-1]=0;
    s.age=atoi(buf);
    printf("please input score:");
    fgets(buf,sizeof(buf),stdin);
    len=strlen(buf);
    buf[len-1]=0;

    s.score=atoi(buf);
    int fd=open("s.info",O_WRONLY|O_CREAT|O_TRUNC,0777);
    len=strlen(s.name);

    int temp;
    temp=htonl(s.age);//    
    write(fd,&temp,sizeof(temp));
    temp=htonl(s.score);
    write(fd,&temp,sizeof(temp));
    temp=htonl(len);
    write(fd,&temp,sizeof(temp));
    write(fd,s.name,strlen(s.name));

    close(fd);


    return 0;
}
