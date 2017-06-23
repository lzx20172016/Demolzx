
int main()
{
    int a=0x12345678;

    char *p=(char *)&a;

    printf("%0x\n",*p);
    printf("%0x\n",*(p+1));
    return 0;
}
