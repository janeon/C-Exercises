
//  Yoda.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/29/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Yoda.hpp"
#include <iostream>
using namespace std;

int Yoda::main(){
    string n,m; cin >> n >> m; string N = ""; string M = "";
    while (n.length() != m.length())
        (n.length() > m.length()) ? m = "0" + m : n = "0" + n;
    // cout << n << endl << m;
    for (int a = max(n.size(), m.size())-1 ; a >= 0; a--) { // iterating from back of string to front
        string sub2, sub;
        sub = n.substr(a,1); sub2 = m.substr(a,1); // getting letter
        // cout << a << " " << atoi(sub.c_str())  << endl;
        if (atoi(sub.c_str()) > atoi(sub2.c_str())) N.insert(0, sub);
        else if (atoi(sub.c_str()) == atoi(sub2.c_str())) {M.insert(0, sub2);N.insert(0, sub);}
        else M.insert(0, sub2);
        // cout << a << " " << sub << " " << sub2 << endl;
    }
    if (N == "") N = "YODA"; if (M == "") M = "YODA";
    bool zero = true;
    for (char c:N){
        if (c != '0') zero = false;
    }
    bool zero1 = true;
    for (char c:M){
        if (c != '0') zero1 = false;
    }
    if (zero) N = "0"; if (zero1) M = "0";
    cout << N << endl << M << endl;
    return 0;
}
