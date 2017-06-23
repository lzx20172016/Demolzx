#include"./header.h"
#include<string>
#include<iostream>
using namespace std;
void tar_file(string filename,FILE *fp)
{

    FILE *psrcfile=fopen(filename.c_str(),"r");

    char buf[4096]={0};

    while(1)
    {
        int ret=fread(buf,1,sizeof(buf),psrcfile);
        if(ret==0)
        {
            break;
        }  

        fwrite(buf,1,ret,fp);
    }

    fclose(psrcfile);

}

void tar_dir(string dirname,FILE *fp)
{
    DIR *dir=opendir(dirname.c_str());
    printf("before readdir\n");
    struct dirent * pdir=readdir(dir);
    printf("after readdir\n");
    while(1)
    { 
//        pdir=readdir(dir);
        if(pdir==NULL)
        {
            break;
        }
        //const char *ctemp=pdir->d_name;
        if(pdir->d_type==DT_REG)
        {
            printf("pdirDT-REG\n");
            tar_file(dirname+"/"+pdir->d_name,fp);
        }else if(pdir->d_type==DT_DIR)
        {
            tar_dir(dirname+"/"+pdir->d_name,fp);
        }
        pdir=readdir(dir);
    }
    closedir(dir);
}

int main(int argc,char *argv[])
{
    cout<<"aaaa\n";
    const char *dst_file=argv[1];
    const char *src_file=argv[2];

    FILE *pdstfile=fopen(dst_file,"w");
    printf("pdsfile worlk\n");
    tar_dir(src_file,pdstfile); 
    fclose(pdstfile);
}
