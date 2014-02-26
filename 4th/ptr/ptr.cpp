#include<iostream>
template <class Type> class Ptr
{
    public:
        Ptr(Type* start,int len)
        {
            _start=start;
            _len=len;
            _pos=0;
        }
        //~Ptr();
        Ptr& operator=(Type* x)
        {
            if(x<0||x>=_len)throw "Out Of Range";
            _pos=x;
            return *this;
        }
        Ptr& operator=(const int& x)
        {
            if(x<0||x>=_len)throw "Out Of Range";
            _pos=x;
            return *this;
        }
        Ptr& operator++()
        {
            if(_pos+1>=_len)throw "Out Of Range";
            _pos++;
            return *this;
        }
        Ptr operator++(int)
        {
            if(_pos+1>=_len)throw "Out Of Range";
            Ptr temp(*this);
            _pos++;
            return temp;
        }
        Ptr& operator--()
        {
            if(_pos-1<0)throw "Out Of Range";
            _pos--;
            return *this;
        }
        Ptr operator--(int)
        {
            if(_pos-1<0)throw "Out Of Range";
            Ptr temp(*this);
            _pos--;
            return temp;
        }
        Type* operator->()
        {
            return _start+_pos;
        }
        Ptr& operator+=(const int& x)
        {
            if(_pos+x>=_len)throw "Out Of Range";
            _pos+=x;
        }
        Ptr operator+(const int& x)
        {
            if(_pos+x>=_len)throw "Out Of Range";
            Ptr temp(*this);
            temp+=x;
            return temp;
        }
        Type& operator*()
        {
            return *(_start+_pos);
        }
    private:
        Type* _start;
        int _len,_pos;

};

/*std::istream& operator >>(std::istream& in,Vec4& x)
{
    for(int i=0;i<x._size;i++)in>>x._data[i];
    return in;
}

std::ostream& operator <<(std::ostream& out,const Vec4& x)
{
    for(int i=0;i<x._size-1;i++)out<<x._data[i]<<" ";
    out<<x._data[x._size-1];
    return out;
}*/
