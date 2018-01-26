//
//  Modulo.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/modulo
//  Created by Jane Hsieh on 1/26/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "Modulo.hpp"
int Modulo::main() {
    int num; vector<int> distincts;
    for (int n = 0; n < 10; n++) {
        cin >> num;
        if (find(distincts.begin(), distincts.end(), num % 42) == distincts.end()) distincts.push_back(num % 42);
    }
    cout << distincts.size();
    return 0;
}
