//  Computes amount of cellular data left in month n+1 given plan and amount used per month
//  Tarifa.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/tarifa
//  Created by Jane Hsieh on 1/20/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//
#include "Tarifa.hpp"
#include <iostream>
using namespace std;

int Tarifa::main(){
    int x,n;
    cin >> x >> n;
    int total = (n+1)*x;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        total -= input;
    }
    cout << total;
    return 0;
}
