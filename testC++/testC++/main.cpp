//
//  main.cpp
//  testC++
//
//  Created by ju on 2017/3/16.
//  Copyright © 2017年 hu. All rights reserved.
//

//#include <iostream>
#include "ensure.cpp"

static int A = 0, B = 0;
#define AB(a, N) std::make_pair(#a, a) << N
#define A(a) AB(a, B)
#define B(a) AB(a, A)
#define ENSURE(b) if (b); else throw EnsureException(#b, __FILE__, __LINE__) << A

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n"<< endl;
    cout << "This is a C++ pointer" << endl;
    
    try
    {
        int a = 2, b = 3;
        ENSURE(a > 1);
        ENSURE(a > 1)(a);
        ENSURE(a > 2 && b <= 3)(a)(b)(5);
    }
    catch (const EnsureException& e)
    {
        cout << "catch exception:\n" << e.what() << endl;
    }
    
    return 0;
}
