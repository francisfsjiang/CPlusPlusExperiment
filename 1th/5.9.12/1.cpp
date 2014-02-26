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
char s1[1000005],s2[10005];
int p[10000];
int kmpstring(string s1,string s2)
{
    int i,j,k;
    int sum=0;
    p[1]=0;
    k=0;
    for(i=2;i<=s2.size();i++)
    {
        for(;k>0&&s2[i-1]!=s2[k];k=p[k]);
        if(s2[i-1]==s2[k])k++;
        p[i]=k;
    }
    k=0;
    for(i=0;i<s1.size();i++)
    {
        for(;k>0&&s1[i]!=s2[k];k=p[k]);
        if(s1[i]==s2[k])k++;
        if(k==s2.size())
        {
            //cout<<"i "<<i<<endl;
            sum++;
            //return i-s2.size()+1;
            k=p[k];
        }
    }
    return sum;
}
int kmpchar(char* s1,char* s2)
{
    int i,j,k;
    int sum=0;
    p[1]=0;
    k=0;
    int l1=strlen(s1);
    int l2=strlen(s2);
    for(i=2;i<=l2;i++)
    {
        for(;k>0&&s2[i-1]!=s2[k];k=p[k]);
        if(s2[i-1]==s2[k])k++;
        p[i]=k;
    }
    k=0;
    for(i=0;i<l1;i++)
    {
        for(;k>0&&s1[i]!=s2[k];k=p[k]);
        if(s1[i]==s2[k])k++;
        if(k==l2)
        {
            sum++;
            k=p[k];
        }
    }
    return sum;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("out.txt","w",stdout);
    char s1[100],s2[100];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        cout<<kmpchar(s1,s2)<<endl;
        string str1(s1),str2(s2);
        cout<<kmpstring(str1,str2)<<endl;
    }
    return 0;
}

