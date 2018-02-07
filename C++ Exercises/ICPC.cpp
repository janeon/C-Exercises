//
//  ICPC.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/27/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "ICPC.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int ICPC::factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    // Ternary operator :)
    // https://stackoverflow.com/questions/2595392/what-does-the-question-mark-and-the-colon-ternary-operator-mean-in-objectiv
}
void ICPC::compare(int m, double steps) {
    // cout << setprecision(15) << m << " " << steps << endl;
    (m >= steps) ? cout << "AC\n" : cout << "TLE\n";
    // anything > 13! exceeds input limit for m anyways
}
int ICPC::main(){
    int m , n , t; cin >> m >> n >> t;
    switch (t) {
        case 1:
            (n >= 13) ? compare(m, m+2) : compare(m, factorial(n));
            break;
        case 2:
            compare(m, pow(2, n));
            break;
        case 3:
            compare(m, pow(n, 4));
            break;
        case 4:
            compare(m, pow(n, 3));
            break;
        case 5:
            compare(m, pow(n, 2));
            break;
        case 6:
            compare(m, n*log2(n));
            break;
        case 7:
            compare(m, n);
            break;
        default:
            break;
    }
    // cout << setprecision(11) << pow(500, 4);
    return 0;
}
