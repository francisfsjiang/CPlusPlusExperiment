#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class Date
{
	public:
        Date(int day,int mon=0,int year=1900)
        {
            tm temp;
            temp.tm_mday=day;
            temp.tm_mon=mon;
            temp.tm_year=year-1900;
            temp.tm_sec=0;
            temp.tm_hour=0;
            temp.tm_min=0;
            timer=mktime(&temp);
        }
        Date(tm temp)
        {
            timer=mktime(&temp);
        }
        Date()
        {
            timer=time(NULL);
        }
		void add_year(int n)
		{
            timer+=n*365*24*60*60;
		}
		void add_day(int n)
		{
            timer+=n*24*60*60;
		}
		void add_month(int n)
		{
            timer+=n*31*24*60*60;
		}
        tm get_tm()const
        {
            tm temp,*p=localtime(&timer);
            temp=*p;
            return temp;
        }
        int get_1970()
        {
            return timer/86400+1;
        }
        Date operator+=(int n)
        {
            this->add_day(n);
            return *this;
        }
        Date operator+(int n)
        {
            this->add_day(n);
            return *this;
        }
        Date operator-=(int n)
        {
            this->add_day(-n);
            return *this;
        }
        Date operator-(int n)
        {
            this->add_day(-n);
            return *this;
        }
        Date operator ++(int n)
        {
            cout<<n<<endl;
            this->add_day(1);
            return *this;
        }
        Date operator --(int n)
        {
            this->add_day(-1);
            return *this;
        }
        bool operator >(Date y)
        {
            return this->timer>y.timer;
        }
        bool operator <(Date y)
        {
            return this->timer<y.timer;
        }
        time_t get_timer()const
        {
            return timer;
        }
	private:
        time_t timer;
};

ostream& operator <<(ostream& stem,const Date& date)
{
    tm temp=date.get_tm();
    stem<<temp.tm_mday<<"/"<<temp.tm_mon+1<<"/"<<temp.tm_year+1900;
    return stem;
}
istream& operator >>(istream& stem,Date& date)
{
    tm temp=date.get_tm();
    stem>>temp.tm_mday>>temp.tm_mon>>temp.tm_year;
    temp.tm_year-=1900;
    date=Date(temp);
    return stem;
}

int main()
{
    Date date1(1,0,1970),date2;
    //int a=date.get_timer();
    //date.add_day(1);
    cout<<date2<<endl;
    cout<<date1<<endl;
    cout<<date2.get_1970()<<endl;
    date1.add_year(3);
    cout<<date1<<endl;
    cout<<(date1>date2)<<endl;
    while(cin>>date1)
    {
        cout<<date1<<endl;
    }
	return 0;
}
