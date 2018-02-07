//
//  GuessNum.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 2/1/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "GuessNum.hpp"
#include <iostream>
using namespace std;
int GuessNum::main() {
    bool guessed = false; int guess, upper, lower; string command; upper = 1001; lower = 1;
    for (int i = 0 ; i < 10 && !guessed; i++) { // tries ++;
        guess = (upper + lower)/2;
        cout << guess << endl;
        getline(cin, command);
        if (command == "correct") {guessed = true; return 0;}
        else {
            (command == "lower") ? upper = guess: lower = guess ;
        }
    }
    return 0;
}
