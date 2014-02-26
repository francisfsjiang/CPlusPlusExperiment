#include<iostream>
#include<map>
#include<cctype>
#include"calculator.h"
using namespace std;
double calc::expr(bool get)
{
    double left=term(get);
    while(true)
    {
        switch(curr_tok)
        {
            case PLUS:
                left+=term(true);
                break;
            case MINUS:
                left-=term(true);
                break;
            default:
                return left;
        }
    }
}
//multiply and divide
double calc::term(bool get)
{
    double left=prim(get);
    while(true)
    {
        switch(curr_tok)
        {
            case MUL:
                left*=prim(true);
                break;
            case DIV:
                if (double d=prim(true))
                {
                    left/=d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}
//prime
double calc::prim(bool get)
{
    if(get)get_token();
    switch(curr_tok)
    {
        case NUMBER:
            {
                double v=number_value;
                get_token();
                return v;
            }
        case NAME:
            {
                double& v=table[string_value];
                if(get_token()==ASSIGN)v=expr(true);
                return v;
            }
        case MINUS:
            return -prim(true);
        case LP:
            {
                double e=expr(true);
                if(curr_tok!=RP)return error(")expected");
                get_token();
                return e;
            }
        default:
            return error("primary expected");
    }
}
//input
calc::Token_value calc::get_token()
{
    char ch;
    do
    {
        if(!cin.get(ch))return curr_tok;
    }while(ch!='\n'&&isspace(ch));
    switch(ch)
    {
        case';':
        case'\n':
            return curr_tok=PRINT;
        case 0:
            return curr_tok=END;
        case'*':
        case'/':
        case'+':
        case'-':
        case'(':
        case')':
        case'=':
            return curr_tok=Token_value(ch);
        case'0':
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
        case'.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch))
            {
                string_value=ch;
                while(cin.get(ch)&&isalnum(ch))string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok=NAME;
            }
            error("bad token");
            return curr_tok=PRINT;
    }
}
//error
double calc::error(const string& s)
{
    no_of_errors++;
    cerr<<"error: "<<s<<'\n'<<endl;
    return 1;
}
