#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <cstring>
#include <ostream>

class String 
{
    public:
        String();
        String(const String&);
        String(const char *);

        String& operator=(const String&);

        int size() const;
        ~String();

        friend String& operator+(String& left, const String& right);
        friend const String operator+(const String& left, const String& right);
        friend String operator+(const char* left, const String& right);

        friend std::ostream& operator<<(std::ostream& os, const String& s);

    private:
        char *rep;
};

String::String() 
{
    rep = new char[1];
    rep[0] = '\0';
}

String::~String() 
{
    delete[] rep;
}

int String::size() const 
{
    return ::strlen(rep);
}

String::String(const String& s) 
{
    rep = new char[s.size() + 1];
    ::strcpy(rep, s.rep);
}

String& String::operator=(const String& s) 
{
    if (rep != s.rep) 
    {
        delete[] rep;
        int lenOrig = s.size() + 1;
        rep = new char[lenOrig];
        ::strcpy(rep, s.rep);
    }

    return *this;
}

String::String(const char *s) 
{
    int lenOrig = ::strlen(s) + 1;
    rep = new char[lenOrig];
    ::strcpy(rep, s);
}

String& operator+(String& left, const String& right) 
{
    char* rep = new char[left.size() + right.size() + 1];
    ::strcpy(rep, left.rep);
    ::strcat(rep, right.rep);
    delete[] left.rep;
    left.rep = rep;
    return left;
}

const String operator+(const String& left, const String& right) 
{
    String retval(left);
    return retval + right;
}

String operator+(const char* left, const String& right) 
{
    return String(left) + right;
}

std::ostream& operator<<(std::ostream& os, const String& s) 
{
    os << s.rep;
    return os;
}

#endif // STRING_HPP