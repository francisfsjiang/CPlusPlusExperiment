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
struct Date
{
    int year,month,day,hour,minute,second;
};
ostream& operator <<(ostream& stem,const Date& temp)
{
    stem<<temp.year<<"-"<<temp.month<<"-"<<temp.day<<"  "<<temp.hour<<":"<<temp.minute<<":"<<temp.second;
    return stem;
}
istream& operator >>(istream& stem,Date& temp)
{
    stem>>temp.year>>temp.month>>temp.day>>temp.hour>>temp.minute>>temp.second;
    return stem;
}
int main()
{
    Date temp;
    cin>>temp;
    cout<<temp;
    Date time = {2013,12,13,20,20,30};
    cout<<time;
    return 0;
}
