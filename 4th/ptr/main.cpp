#include<iostream>
#include<cstdlib>
#include"ptr.cpp"
using namespace std;
struct tc
{
    int a;
};
int main()
{
    tc data[50];
    data[1].a=5;
    data[6].a=20;
    Ptr<tc> temp(data,50);
    try
    {
        temp++;
        cout<<(temp->a)<<endl;
        temp+=60;
        cout<<(temp->a)<<endl;
        (*temp).a=5;
        cout<<(temp->a)<<endl;
        temp->a=8;
        cout<<(temp->a)<<endl;
    }
    catch(char const* e)
    {
        cout<<e<<endl;
        exit(0);
    }
    return 0;
}
