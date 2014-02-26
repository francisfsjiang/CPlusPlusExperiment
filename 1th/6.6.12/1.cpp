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
struct result
{
    double sum,ave,mid;
};
map<string,vector<double> > m;
result sum(vector<double>& vec)
{
    result temp;
    temp.ave=temp.mid=temp.sum=0;
    sort(vec.begin(),vec.end());
    
    vector<double>::iterator iter=vec.begin();
    while(iter!=vec.end())
    {
        temp.sum+=(*iter++);
    }
    while(iter++!=vec.end())temp.sum+=(*iter);
    temp.ave=temp.sum/vec.size();
    if(vec.size()%2==0)temp.mid=(vec[vec.size()/2]+vec[vec.size()/2-1])/2;
    else temp.mid=vec[vec.size()/2];
    return temp;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    string str1,str2;
    double n;
    result temp,total;
    total.sum=total.ave=total.mid=0;
    while(cin>>str1>>str2>>n)
    {
        m[str1+" "+str2].push_back(n);
    }        
    map<string,vector<double> >::iterator iter=m.begin();
    while(iter!=m.end())
    {
        temp=sum(iter->second);
        cout<<iter->first<<" sum: "<<temp.sum<<" ave: "<<temp.ave<<" mid: "<<temp.mid<<endl;
        iter++;
        total.sum+=temp.sum;
    }
    total.ave=total.sum/m.size();
    cout<<"total : sum:"<<total.sum<<" ave: "<<total.ave<<endl;
    return 0;
}
