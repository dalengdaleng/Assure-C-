//
//  ensure.cpp
//  testC++
//
//  Created by ju on 2017/3/17.
//  Copyright © 2017年 hu. All rights reserved.
//

#include <stdio.h>

#include <exception>
#include <sstream>
#include <iostream>

using namespace std;

class EnsureException:
public std::exception
{
public:
    EnsureException(const char *exp, const char *file, int line)
    {
    std::ostringstream so;
    so << "ensure failed : " << exp << '\n';
    so << file << '(' << line << ')' << '\n';
    so << "context variables:\n";
    m_what = so.str();
    }
    ~EnsureException() throw (){}
    
    template<typename T>
    EnsureException& operator << (const std::pair<const char *, T>& p)
    {
    std::ostringstream so;
    so << '\t' << p.first << " : " << p.second << '\n';
    m_what += so.str();
    return *this;
    }
    EnsureException& operator << (int){ return *this; }
    
    const char *what() const throw ()
    { 
        return m_what.c_str();
    }
private:
    mutable std::string m_what;
};
