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
char* itoa(int n,char b[])
{
    int len=0,temp;
    temp=1;
    while(temp<=n)
    {
        len++;
        temp*=10;
    }
    if(n==0)len=1;
    for(int i=len-1;i>=0;i--)
    {
        b[i]=n%10+'0';
        n=n/10;
    }
    b[len]=0;
    return b;
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    char b[1000];
    printf("%s\n",itoa(0,b));
    printf("%s\n",itoa(1,b));
    printf("%s\n",itoa(52,b));
    printf("%s\n",itoa(99,b));
    printf("%s\n",itoa(100,b));
    return 0;
}
