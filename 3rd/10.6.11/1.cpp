#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<vector>
using namespace std;
map<string,int> level;
int tonum(const string& str)
{
    int sum=0,temp=1;
    for(int i=str.size()-1;i>=0;i--,temp*=10)sum+=(str.c_str()[i]-'0')*temp;
    return sum;
}
string tostring(int a)
{
    /*char temp[50];
    int i=0;
    while(a>0)
    {
        temp[i++]='0'+a%10;
        a/=10;
    }
    temp[i]=0;*/
    string str="",out="";
    while(a>0)
    {
        str+='0'+a%10;
        a/=10;
    }
    for(int i=str.size()-1;i>=0;i--)out+=str[i];
    return out;
}
class Expr
{
    public:
        Expr(const char* s)
        {
            expr=s;
        }
        Expr(const string& str)
        {
            expr=str;
        }
        int eval()
        {
            this->separate(this->expr);
            this->next_to_mid();
            stack<string> symbol;
            int sum=0,a,b;
            auto iter=next_expr.begin();
            while(iter!=next_expr.end())
            {
                if(level[*iter]==0)
                {
                    symbol.push(*iter);
                }
                else
                {
                    b=tonum(symbol.top());
                    symbol.pop();
                    a=tonum(symbol.top());
                    symbol.pop();
                    //cout<<a<<" "<<b<<endl;
                    if((*iter)=="+")
                    {
                        symbol.push(tostring(a+b));
                    }
                    else if((*iter)=="-")
                    {
                        symbol.push(tostring(a-b));
                    }
                    else if((*iter)=="*")
                    {
                        symbol.push(tostring(a*b));
                    }
                    else if((*iter)=="/")
                    {
                        symbol.push(tostring(a/b));
                    }
                }
                iter++;
            }
            return tonum(symbol.top());
        }
        void print()
        {
            for(auto i=this->mid_expr.begin();i!=this->mid_expr.end();i++)cout<<(*i)<<" ";
            cout<<endl;
            for(auto i=this->next_expr.begin();i!=this->next_expr.end();i++)cout<<(*i)<<" ";
            cout<<endl;
        }
    //private:
        void separate(string str)
        {
            int head=0,len=1;
            while(head<str.size())
            {
                if(level[str.substr(head,1)]!=0)
                {
                    mid_expr.push_back(str.substr(head,1));
                }
                else
                {
                    while(head+len<str.size()&&level[str.substr(head+len,1)]==0){len++;}
                    mid_expr.push_back(str.substr(head,len));
                }
                head+=len;
                len=1;
            }
        }
        void next_to_mid()
        {
            auto iter=mid_expr.begin();
            stack<string> symbol;
            int lv;
            while(iter!=mid_expr.end())
            {
                if((*iter)=="(")
                {
                    symbol.push(*iter);
                }
                else if((*iter)==")")
                {
                    while(!symbol.empty()&&symbol.top()!="(")
                    {
                        next_expr.push_back(symbol.top());
                        symbol.pop();
                    }
                    symbol.pop();
                }
                else if(level[*iter]==0)
                {
                    next_expr.push_back(*iter);
                }
                else
                {
                    lv=level[*iter];
                    //cout<<lv<<endl;
                    while(!symbol.empty()&&level[symbol.top()]>=lv)
                    {
                        next_expr.push_back(symbol.top());
                        symbol.pop();
                    }
                    symbol.push(*iter);
                }
                iter++;
            }
            while(!symbol.empty())
            {
                next_expr.push_back(symbol.top());
                symbol.pop();
            }
        }
        string expr;
        vector<string> next_expr;
        vector<string> mid_expr;
};                
void init()       
{                 
    level["("]=1; 
    level[")"]=1;
    level["+"]=2;
    level["-"]=2;
    level["*"]=3;
    level["/"]=3;
}

int main()
{
    init();
    //Expr expr("(5+7*(6+12))*(36/35)");
    string str;
    while(cin>>str)
    {
        Expr expr(str);
        //for(auto i=expr.mid_expr.begin();i!=expr.mid_expr.end();i++)cout<<(*i)<<endl;
        //for(auto i=expr.next_expr.begin();i!=expr.next_expr.end();i++)cout<<(*i)<<endl;
        cout<<expr.eval()<<endl;
        expr.print();
    }
    return 0;
}
