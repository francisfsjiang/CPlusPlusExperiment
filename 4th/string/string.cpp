#include<iostream>
#include<cstring>
//#include<string>


class String
{
    public:
        String()
        {
            _data=new char[1];
            _size=0;
            *_data = '\0';
        }
        String(const char* str)
        {
            _size=strlen(str);
            _data=new char[_size + 1];
            strcpy(_data, str);
        }
        String(const String& rhs)
        {
            _data=new char[rhs.size() + 1];
            _size=rhs.size();
            strcpy(_data, rhs.c_str());
        }
        ~String()
        {
            delete[] _data;
        }
        String& operator=(String rhs)
        {
            std::swap(_data, rhs._data);
            std::swap(_size,rhs._size);
            return *this;
        }
        bool operator==(const String& str)
        {
            return !strcmp(str.c_str(),_data);
        }
        bool operator<(const String& str)const
        {
            for(int i=0;i<std::max(_size,str.size());i++)
            {
                if(_data[i]<str.c_str()[i])return true;
                else if(_data[i]>str.c_str()[i])return false;
            }
            return false;
        }
        bool operator>(const String& str)
        {
            for(int i=0;i<std::max(_size,str.size());i++)
            {
                if(_data[i]>str.c_str()[i])return true;
                else if(_data[i]<str.c_str()[i])return false;
            }
            return false;
        }
        String& operator+=(const String& str)
        {
        	char* temp=new char[_size+str._size];
        	std::strcpy(temp,_data);
        	for(int i=0;i<str._size;i++)
        	{
        		temp[_size+i]=str._data[i];
        	}
        	temp[_size+str._size]='\0';
        	delete _data;
        	_data=temp;
        	return *this;
        }
        String operator+(const String& str);
        char& operator[](const int a)
        {
            return *(_data+a);
        }
        int size() const
        {
            return _size;
        }
        const char* c_str() const
        {
            return _data;
        }
 
    private:
        char* _data;
        int _size;
};

std::ostream& operator<<(std::ostream& out,const String& str)
{
    out<<str.c_str();
    return out;
}
std::istream& operator>>(std::istream& in,String& str)
{
    std::string temp;
    in>>temp;
    str=temp.c_str();
    return in;
}

String String::operator+(const String& str)
        {
        	String temp(*this);
        	temp+=str;
        	std::cout<<temp<<std::endl;
        	*this=temp;
        	return *this;
        }
