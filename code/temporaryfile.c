//给出创建临时文件的实例
int main()
{
    char tmp_path[256];

    strcpy(tmp_path,"/tmp/save_the_world_xxxxxx");
    mkstemp(tmp_path);

    printf("%s\n",tmp_path);

}
