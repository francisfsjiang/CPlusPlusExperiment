#include<iostream>
#include"vec.cpp"
using namespace std;
int main()
{
    Vec4 a(5);
    cout<<a<<endl;
    cout<<a[3]<<endl;
    Vec4 b(1,2,3,4);
    a=3;
    cout<<a<<endl;
    cout<<b<<endl;
    a=b;
    cout<<a<<endl;
    cout<<b<<endl;
    a+=b;
    a=a+b;
    a-=b;
    a=a-b;
    a*=b;
    a=a*b;
    a/=b;
    a=a/b;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
