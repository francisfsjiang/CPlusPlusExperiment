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
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    string str;
    vector<string> vec;
    map<string,bool> exist;
    cout<<"Before sort"<<endl;
    while(cin>>str)
    {
        if(str=="Quit")break;
        cout<<str<<endl;
        if(exist[str]==0)
        {
            vec.push_back(str);
            exist[str]=1;
        }
    }
    cout<<endl<<"After sort"<<endl;
    sort(vec.begin(),vec.end());
    vector<string>::iterator iter=vec.begin();
    while(iter!=vec.end())
    {
        cout<<(*iter)<<endl;
        iter++;
    }
    return 0;
}
