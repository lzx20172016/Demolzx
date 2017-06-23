#include"./header.h"



int main(int argc,char *argv[])
{

    if(argc!=2)//排除错误情况
    {
        printf("error arguments\n");
        return 0;
    }

    const char *src=argv[1];//获得打包文件的地址

    FILE *pfread=fopen(src,"r");//读打包文件之前先打开文件

    char buf[4096];//读文件缓冲区设置

    if(fgets(buf,sizeof(buf),pfread)==0)//读打包文件第一行
        return 0;
    while(1)
    {
        if(strcmp(buf,"d\n")==0)//strcmp用法不熟悉
        {//此处条件成立说明该行是目录记录
            fgets(buf,sizeof(buf),pfread);//必须再读一次，因为第一次结果是d；本次是为了获得目录的名字
            
            printf("buf,d\n");
            buf[strlen(buf)-1]=0;//将该行最后的换行符去掉，因为目录不能有换行符
            mkdir(buf,0777);
            printf("%s\n",buf);
        }else if(strcmp(buf,"f\n")==0)//说明是文件
        {

            printf("buf,f\n");
            fgets(buf,sizeof(buf),pfread);//再读一次文件获得文件名
            buf[strlen(buf)-1]=0;//开始为写文件做准备
            FILE *pfwrite=fopen(buf,"w");
            printf("%s\n",buf);
            printf("pfwrite works\n");
            fgets(buf,sizeof(buf),pfread);//再读一次文件获得文件的尺寸
            buf[strlen(buf)-1]=0;//atoi转化为整数，排除换行符的干扰

            int len=atoi(buf);//atoi的对象不能有换行符

            while(1)//开始写文件
            {

                printf("buf,while1\n");
                int lenread=len>sizeof(buf)?sizeof(buf):len;//借用缓冲区buf读文件时不能超过缓冲区大小

                //fgets(buf,lenread,pfwrite);//开始读数据，因为fgets会自动添加终结符，所以不需要情况buf//此处有错误，没有考虑到应该从pfread中读，而不是pfwrite
                // fgets(buf,lenread,pfread);因为下文中要用fwrite，此处用该用fread读
                // fread(buf,lenread,1,pfread);因为一次性读lenread字节的数据不能读够，下文中写文件肯定会出错
                int ret=fread(buf,1,lenread,pfread);

                if(ret<=0)
                {
                    break;
                }

                printf("buf,fread%d\n",ret);
                fwrite(buf,ret,1,pfwrite);//将读到的数据写入文件

                printf("buf fwrite\n");
                len-=ret;//写完后，要将要读的长度减去已经读的长度
                if(len<=0)break;

                printf("len works\n");
            }
            fclose(pfwrite);
        }
        if(fgets(buf,sizeof(buf),pfread)==NULL)
            break;

    }
}
