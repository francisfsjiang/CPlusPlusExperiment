#include<iostream>
#include<cmath>
#include"calculator.h"
using namespace std;

int main()
{
    calc::table["pi"]=M_PI;
    calc::table["e"]=M_E;
    while(cin)
    {
        calc::get_token();
        if(calc::curr_tok==calc::END)break;
        if(calc::curr_tok==calc::PRINT)continue;
        cout<<calc::expr(false)<<endl;
    }
    return calc::no_of_errors;
}
