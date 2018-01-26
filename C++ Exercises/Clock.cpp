//
//  Clock.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/24/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "Clock.hpp"
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int Clock::main(){
    cpp_int n = static_cast<cpp_int>("100000000000000");
    cpp_int digit = 1; cpp_int total = 0; cpp_int curr;
    vector<string> prefixes = {"1","2","3","4","32","123","43","2123","432","1234","32123","43212","34321","23432",""};
    vector<string> suffixes = {"234321","343212","432123","321234","123432","432123","212343","432123","123432","321234","432123","343212","234321","123432","123432"};
    while (digit <= n) {
        cpp_int quotient = digit / 15; int rem = (digit % 15).template convert_to<int>();
        if (rem == 0) rem = 15; rem --; 
        string current = prefixes[rem];
        for (int times = 0; times < quotient; times++) current = current + suffixes[rem];
        curr = static_cast<cpp_int>(current); total += curr; total = total % 123454321;
        cout << digit << " Digit :: Total " << total << endl;
        digit ++;
    }
    /*
    while (digit <= n) { // until desired n is reached, keep iterating through sequence
        int sum = 0; // initializing sum of digits of current number
        string current = ""; // initializing number as string
        while (sum < digit) {
            char letter = seq[pos]; current += letter; // appending a digit
            int num = int(letter)- 48; // conversion of digit to int
            sum += num; //  summing digits
            pos ++; pos = pos % 6; // incrementing position count
        }
        curr = static_cast<cpp_int>(current);
        total += curr;
        cout << digit << " Digit :: curren]t " << current << endl;
        // cout << current << endl;
        digit++;
     }
     */
    // cout << total << endl;
    cout << "Answer is" << total % 123454321;
    return 0;
}










