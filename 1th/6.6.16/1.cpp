#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<list>
#include<stack>
#include<algorithm>
#define bug(s) cout<<#s<<"="<<s<<endl;
#define bugs(a,b) cout<<#a<<" ";for(int zz=0;zz<=b;zz++)cout<<a[zz]<<" ";cout<<endl;
using namespace std;
int atoi(const char* str)
{
    int l=strlen(str);
    int sum=0,temp=1;
    if(l>2&&str[0]=='0'&&str[1]=='x')
    {
        for(int i=l-1;i>=2;i--)
        {
            if('0'<=str[i]&&str[i]<='9')sum+=(str[i]-'0')*temp;
            else sum+=(str[i]-'a'+10)*temp;
            temp*=16;
        }
        return sum;
    }
    else if(l>1&&str[0]=='0')
    {
        for(int i=l-1;i>=1;i--)
        {
            sum+=(str[i]-'0')*temp;
            temp*=8;
        }
        return sum;
    }
    else
    {
        for(int i=l-1;i>=0;i--)
        {
            sum+=(str[i]-'0')*temp;
            temp*=10;
        }
        return sum;
    }
}
int atoi(const string& str)
{
    int l=str.size();
    int sum=0,temp=1;
    if(l>2&&str[0]=='0'&&str[1]=='x')
    {
        for(int i=l-1;i>=2;i--)
        {
            if('0'<=str[i]&&str[i]<='9')sum+=(str[i]-'0')*temp;
            else sum+=(str[i]-'a'+10)*temp;
            temp*=16;
        }
        return sum;
    }
    else if(l>1&&str[0]=='0')
    {
        for(int i=l-1;i>=1;i--)
        {
            sum+=(str[i]-'0')*temp;
            temp*=8;
        }
        return sum;
    }
    else
    {
        for(int i=l-1;i>=0;i--)
        {
            sum+=(str[i]-'0')*temp;
            temp*=10;
        }
        return sum;
    }
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cout<<atoi("0x23")<<endl;
    cout<<atoi(string("0x23"))<<endl;
    cout<<atoi("023")<<endl;
    cout<<atoi(string("023"))<<endl;
    cout<<atoi("23")<<endl;
    cout<<atoi(string("23"))<<endl;

    return 0;
}
