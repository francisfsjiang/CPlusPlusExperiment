#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class Date
{
	public:
        Date(const tm& data)
        {
            a=data;
        }
        Date(const tm* data)
        {
            a=*data;
        }
		void addayear()
		{
			a.tm_year++;
		}
		void addaday()
		{
			a.tm_mday++;
		}
		void addamonth()
		{
			a.tm_mon++;
		}
        int weekday()const
        {
            return a.tm_wday;
        }
        Date next_Mon()
        {
            time_t temp=mktime(&a);
            temp+=86400;
            while(localtime(&temp)->tm_wday!=1)
            {
                temp+=86400;
            }
            return Date(localtime(&temp));
        }
		tm a;
	private:
};

ostream& operator <<(ostream& stem,const Date& temp)
{
    stem<<temp.a.tm_year+1900<<"-"<<temp.a.tm_mon<<"-"<<temp.a.tm_mday<<"  "<<temp.a.tm_wday<<"  "<<temp.a.tm_hour<<":"<<temp.a.tm_min<<":"<<temp.a.tm_sec;
    return stem;
}
istream& operator >>(istream& stem,Date& temp)
{
    stem>>temp.a.tm_year>>temp.a.tm_mon>>temp.a.tm_mday>>temp.a.tm_hour>>temp.a.tm_min>>temp.a.tm_sec;
    temp.a.tm_year-=1900;
    return stem;
}

int main()
{
    time_t timer=time(NULL);
    struct tm* local=localtime(&timer);
    /*cout<<timer<<endl;
    cout<<(date->tm_wday)<<endl;
    date->tm_year++;
    cout<<mktime(date)<<endl;*/
    Date mine(local);
    cout<<"localtime: "<<mine<<endl;
    Date temp=mine.next_Mon();
    cout<<"next MON: "<<temp<<endl;
    cin>>mine;
    cout<<mine<<endl;
    temp=mine.next_Mon();
    cout<<temp<<endl;
	return 0;
}
