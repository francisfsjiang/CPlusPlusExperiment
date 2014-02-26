#include<iostream>
class complex
{
    public:
        complex(double x,double y):re(x),im(y){}
        complex(double x):re(x),im(0){}
        complex():re(0),im(0){}
        /*complex& operator=(const complex& x)
        {
            this->im=x.im;
            this->re=x.re;
            return *this;
        }*/
        /*complex& operator=(const double& x)
        {
            this->re=x;
            this->im=0;
            return *this;
        }*/
        complex& operator+=(const complex& y)
        {
            this->re+=y.re;
            this->im+=y.im;
            return *this;
        }
        complex operator+(const complex& x)
        {
            complex a(*this);
            a+=x;
            return a;
        }
        //complex& operator+=(const double& x);
        //complex operator+(const double& x);
        complex& operator-=(const complex& x)
        {
            this->re-=x.re;
            this->im-=x.im;
            return *this;
        }
        //complex& operator-=(const double& x);
        complex operator-(const complex& x)
        {
            complex a(*this);
            a-=x;
            return a;
        }
        //complex operator-(const double& x);
        complex& operator*=(const complex& x)
        {
            this->re=x.re*this->re-x.im*x.re;
            this->im=x.re*this->im+x.im*this->re;
            return *this;
        }
        //complex& operator*=(const double& x);
        complex operator*(const complex& x)
        {
            complex a(*this);
            a*=x;
            return a;
        }
        //complex operator*(const double& x);
        complex& operator/=(const complex& x);
        //complex& operator/=(const double& x);
        complex operator/(const complex& x);
        //complex operator/(const double& x);
        bool operator==(const complex& x)
        {
            if(this->im==x.im&&this->re==x.re)return true;
            else return false;
        }
        bool operator!=(const complex& x)
        {
            return !((*this)==x);
        }
        double real()
        {
            return re;
        }
        double imag()
        {
            return im;
        }
        friend std::ostream& operator<<(std::ostream& output,const complex& x);
        friend std::istream& operator>>(std::istream& input,complex& x);
        friend complex operator+(const double& x,const complex& y);
    private:
        double re,im;
};
std::ostream& operator <<(std::ostream& output,const complex& x)
{
    output<<x.re;
    if(x.im<0)output<<x.im<<"i";
    else if(x.im==0)output<<"+i";
    else output<<"+"<<x.im<<"i";
    return output;
}
std::istream& operator >>(std::istream& input,complex& x)
{
    input>>x.re>>x.im;
    return input;
}
complex operator+(const double& x,const complex& y)
{
    return complex(x+y.re,y.im);
}

