#include"../header.h"
//从磁盘中读数据到内存

struct student
{
    char *name;
    int score;
    int age;
};


int main()
{
    int tmp;
    struct student s;
    int fd=open("s.info",O_RDONLY);
    read(fd,&tmp,sizeof(tmp));
//    s.age=tmp;
    s.age=ntohl(tmp);
    read(fd,&tmp,sizeof(tmp));
//    s.score=tmp;
    s.score=ntohl(tmp);
    int len;
    read(fd,&tmp,sizeof(tmp));
    len=ntohl(tmp);
    s.name=malloc(len+1);
    s.name[len]='\0';
    read(fd,s.name,len);
    close(fd);
    printf("name is %s,age=%d,score=%d\n",s.name,s.age,s.score);

    return 0;
}
