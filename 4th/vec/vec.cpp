typedef float _elem ;
const _elem INF=1e20;
class Vec4
{
    public:
        Vec4(){};
        Vec4(_elem x)
        {
            _data=new _elem[_size];
            for(int i=0;i<_size;i++)_data[i]=x;
        }
        Vec4(_elem x,_elem y,_elem z,_elem w)
        {
            _data=new _elem[_size];
            _data[0]=x;
            _data[1]=y;
            _data[2]=z;
            _data[3]=w;
        }
        Vec4(const Vec4& x)
        {
            _data=new _elem[_size];
            for(int i=0;i<_size;i++)_data[i]=x._data[i];
        }
        ~Vec4()
        {
            delete _data;
        }
        _elem& operator=(Vec4 x)
        {
            std::swap(_data,x._data);
        }
        _elem& operator[](const int& x)
        {
            return *(_data+x);
        }
        Vec4& operator+=(const Vec4& x)
        {
            for(int i=0;i<_size;i++)_data[i]+=x._data[i];
            return *this;
        }
        Vec4 operator+(const Vec4& x)
        {
            Vec4 temp=*this;
            temp+=x;
            return temp;
        }
        Vec4& operator-=(const Vec4& x)
        {
            for(int i=0;i<_size;i++)_data[i]-=x._data[i];
            return *this;
        }
        Vec4 operator-(const Vec4& x)
        {
            Vec4 temp=*this;
            temp-=x;
            return temp;
        }
        Vec4& operator*=(const Vec4& x)
        {
            for(int i=0;i<_size;i++)_data[i]*=x._data[i];
            return *this;
        }
        Vec4 operator*(const Vec4& x)
        {
            Vec4 temp=*this;
            temp*=x;
            return temp;
        }
        Vec4& operator/=(const Vec4& x)
        {
            for(int i=0;i<_size;i++)
            {
                if(x._data[i]==0)_data[i]=INF;
                else _data[i]/=x._data[i];
            }
            return *this;
        }
        Vec4 operator/(const Vec4& x)
        {
            Vec4 temp=*this;
            temp/=x;
            return temp;
        }

        static const int _size=4;
        _elem* _data;
    private:

};

std::istream& operator >>(std::istream& in,Vec4& x)
{
    for(int i=0;i<x._size;i++)in>>x._data[i];
    return in;
}

std::ostream& operator <<(std::ostream& out,const Vec4& x)
{
    for(int i=0;i<x._size-1;i++)out<<x._data[i]<<" ";
    out<<x._data[x._size-1];
    return out;
}
