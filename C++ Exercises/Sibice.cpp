//
//  Sibice.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/27/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Sibice.hpp"
#include <iostream>
#include <cmath>
using namespace std;
int Sibice::main(){
    int n, w, h, diag, input; cin >> n >> w >> h;
    diag = sqrt(pow(w, 2)+pow(h, 2));
    for (int i = 0; i < n; i++) {
        cin >> input; (input <= diag) ? cout << "DA\n" : cout << "NE\n";
    }
    return 0;
}
