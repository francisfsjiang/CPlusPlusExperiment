#include<iostream>
#include"complex.cpp"
using namespace std;
int main()
{
    complex a(4,5),b(3,4),c;
    a+=b+=b;
    a+=5;
    a=4;
    cout<<a<<endl;
    c=a+b;
    cout<<c<<endl;
    c=a;
    cout<<c<<endl;
    cout<<(a!=c)<<endl;
    cin>>b;
    cout<<b<<endl;
    b=3+a;
    cout<<b<<endl;
    return 0;
}
