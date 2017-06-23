#include"./header.h"



int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("arguments are not correct\n");
        return 0;
    }
    const char * src=argv[1];
    FILE *fp=fopen(src,"r");

    char buf[4096];

    while(1)
    {
        printf("while in:\n");
        if(fgets(buf,sizeof(buf),fp)==NULL)
            return 0;
        printf("fgets works\n");
        if(strcmp(buf,"f\n")==0)
        {
            printf("buf,f works\n");
            fgets(buf,sizeof(buf),fp);
            buf[strlen(buf)-1]=0;
    FILE *fcre=fopen(buf,"w");

            fgets(buf,sizeof(buf),fp);
            buf[strlen(buf)-1]=0;//为了进行atoi必须芝铃

            int len=atoi(buf);
            printf("atoi works\n");
            //写文件
            while(1)
            {
                int ret=len>sizeof(buf)?sizeof(buf):len;
                if(ret<=0)
                {
                    break;
                }
                printf("ret works\n");
                fwrite(buf,ret,1,fcre);
                len-=ret;
            }
            fclose(fcre);
        }
        else if(strcmp(buf,"d\n")==0)
        {
            printf("buf,d works\n");
            fgets(buf,sizeof(buf),fp);//获得目录的名字
            buf[strlen(buf)-1]=0;
            mkdir(buf,0777);
            printf("mkdir works\n");
        }
    }
    fclose(fp);
}

