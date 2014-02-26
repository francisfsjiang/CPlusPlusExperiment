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
const int size=1000;
char* mix(const char* str1,const char* str2)
{
    int l1=strlen(str1);
    int l2=strlen(str2);
    char* temp=new char[l1+l2+1];
    for(int i=0;i<l1;i++)temp[i]=str1[i];
    for(int i=0;i<l2;i++)temp[i+l1]=str2[i];
    temp[l1+l2]=0;
    return temp;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    char str1[size],str2[size];
    char *pstr;
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        pstr=mix(str1,str2);
        printf("%s\n",pstr);
        delete pstr;
        
    }
    return 0;
}
