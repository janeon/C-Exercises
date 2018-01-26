//
//  Character_Dev.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/character
//  Created by Jane Hsieh on 1/26/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//
#include "Character_Dev.hpp"
#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
int Char::main() {
    /*
    int n; cin >> n; boost::multiprecision::cpp_int ans = static_cast<boost::multiprecision::cpp_int>(pow(2, n));
    cout << ans  - n - 1; // bit-wise shift
     */
    // Alternatively, use bit-wise shift
    int n; cin >> n;
    cout << (1 << n)  - n - 1; // bit-wise shift to the left by n
    // reference for bit-wise shifts
    //  https://stackoverflow.com/questions/141525/what-are-bitwise-shift-bit-shift-operators-and-how-do-they-work
    return 0;
}

