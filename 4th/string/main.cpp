#include<iostream>
#include<vector>
#include<map>
#include<array>
#include"string.cpp"
using namespace std;
int main()
{
    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    s2 = s1;
    s1="1234";
    cout<<s1<<endl;
    cout<<s2<<endl;
    s2[2]='0';
	cout<<s1<<endl;
    cout<<s2<<endl;
    //s1+=s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    //s3=s1+s2;
    //cout<<s1<<endl;
    //cout<<s2<<endl;
    cout<<s3<<endl;
    vector<String> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back("good job");
    map<String,String> dict;
    dict[s1]=s2;
    dict["2423"]="dwad";
    cin>>s1;
    cout<<s1<<endl;
    //array<int,6> a;
    return 0;
}
