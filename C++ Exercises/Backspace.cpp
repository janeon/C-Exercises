//
//  Backspace.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/31/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Backspace.hpp"
#include <iostream>
#include <vector>
using namespace std;
int Backspace::main() {
    string input; cin >> input; vector<char> output;
    for (char c:input) (c != '<') ? output.push_back(c) : output.pop_back();
    for (char c : output) cout << c;
    return 0;
}
