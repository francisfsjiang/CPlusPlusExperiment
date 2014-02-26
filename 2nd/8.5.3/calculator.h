#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED
#include<map>
#include<iostream>
#include<string>
namespace calc
{
    enum Token_value{
        NAME,
        NUMBER,
        END,
        PLUS='+',
        MINUS='-',
        MUL='*',
        DIV='/',
        PRINT=';',
        ASSIGN='=',
        LP='(',
        RP=')'
    };
    Token_value curr_tok=PRINT;
    double number_value;
    std::string string_value;
    std::map<std::string,double>table;
    int no_of_errors;

    //plus and minus
    double expr(bool get);
    //multiply and divide
    double term(bool get);
    //prime
    double prim(bool get);
    //input
    Token_value get_token();
    //error
    double error(const std::string& s);


}

#include"calculator.cpp"
#endif
