#include<iostream>
#include<cstdarg>
using namespace std;
void error(const char* format ...)
{
	va_list args;
	va_start(args,format);
	int i=0;
	while(format[i]!=0)
	{
		if(format[i]=='%'&&format[i+1]!=0)
		{
			if(format[i+1]=='s')
			{
				char* pch=va_arg(args,char*);
				cout<<pch;
			}
			else if (format[i+1]=='c')
			{
				char ch=va_arg(args,int);
				cout<<ch;
			}
			else if (format[i+1]=='d')
			{
				int a=va_arg(args,int);
				cout<<a;
			}
			i+=2;
		}
		else
		{
			cout<<format[i];
			i++;
		}
	}
	va_end(args);
}
int main(int argc,char* argv[])
{
	char data[6]="str";
	int a=5;
	char ch='x';
	error("a%saa%da%ca",data,a,ch);
	return 0;
}
