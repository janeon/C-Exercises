//
//  Patuljci.cpp
//  C++ Exercises
//  https://open.kattis.com/submissions/2507191
//  Created by Jane Hsieh on 1/26/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Patuljci.hpp"
#include <iostream>
#include <vector>
using namespace std;
int Patuljci::main() {
    int input, sum; input = sum = 0; vector<int> inputs;
    for (int i = 0; i < 9; i++) {
        cin >> input; sum += input; inputs.push_back(input);
    }
    int remainder = sum - 100; int first; int second;
    for (int i = 0; i < 9 ; i++) {
        for (int j = 0; j < 9; j++) {
            // brace for the appearance of 50
            if ((inputs[i]+inputs[j] == remainder) && (i != j)) {first = inputs [i]; second = inputs[j];}
        }
    }
    
    int total = 0;
    for (int k = 0; k < 9; k++) {
        if (inputs[k] == first || inputs[k] == second) continue;
        else {
            total += inputs[k];
            cout << inputs[k] << endl;
        }
    }
    if (total == 100) return 0;
    else return 100;
}
