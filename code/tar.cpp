#include<string>
using namespace std;
#include"./header.h"//注意本打包程序不能在开始打开一个文件
void tar_file(string src,FILE *fp)
{
    fprintf(fp,"f\n");

    fprintf(fp,"%s\n",src.c_str());
    printf("tar file %s\n",src.c_str());
      struct stat stat_buf;
    stat(src.c_str(),&stat_buf);
    fprintf(fp,"%d\n",(int)stat_buf.st_size);
    FILE *fpin=fopen(src.c_str(),"r");

    char buf[4096];
    while(1)
    {
        int ret=fread(buf,1,sizeof(buf),fpin);
        if(ret<=0)break;
        fwrite(buf,ret,1,fp);
    }

    fclose(fpin);

}
void tar_dir(string src,FILE *fp)
{
    fprintf(fp,"d\n");
    fprintf(fp,"%s\n",src.c_str());
  //  printf("tar dir %s\n",src.c_str());
    DIR *dir=opendir(src.c_str());

    while(1)
    {
        struct dirent *entry=readdir(dir);
        if(entry==NULL)break;
        if(strcmp(entry->d_name,"..")==0)continue;
        if(strcmp(entry->d_name,".")==0)continue;

        if(entry->d_type==DT_REG)
        {
            tar_file(src+"/"+entry->d_name,fp);
        }else if(entry->d_type==DT_DIR)
        {
            tar_dir(src+"/"+entry->d_name,fp);
        }
    }

    closedir(dir);
}
int main(int argc,char *argv[])
{
    const char *dst=argv[1];
    const char *src=argv[2];
    
    FILE *fp=fopen(dst,"w");   
    
    tar_dir(src,fp);
    fclose(fp);


}
