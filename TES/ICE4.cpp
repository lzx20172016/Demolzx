#include<list>
using namespace std;
list<int>datas;
#include<signal.h>
void handle(int v)
{
    datas.push_back(1000);
}


int main()
{
    signal(SIGINT,handle);
    while(1)
    {
        datas.push_back(100);
    }


}
