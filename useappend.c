#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
//用append命令创建文件，并写入10个hello
int main()
{
    int fd=open("a.txt",O_WRONLY|O_APPEND);
    
    for(int i=0;i<10;i++)
    {
    write(fd,"hello",5);
    
    sleep(1);
    }


}
