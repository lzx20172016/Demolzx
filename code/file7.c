#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd=open("a.txt",O_WRONLY|O_APPEND);

    for(int i=0;i<10;i++)
    {
    write(fd,"world",5);
    sleep(1);
    }

}
