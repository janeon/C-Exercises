//
//  TPH.cpp
//  C++ Exercises
//  Triangular, Pentagonal, Hexagonal
//  Created by Jane Hsieh on 1/23/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "TPH.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>

vector<int> TPH::triangular(int n, int m) {
    vector<int> nums;
    for (int a = n; a < m; a++)
        nums.push_back(0.5*a*(a+1));
    return nums;
}

vector<int> TPH::pentagonal(int n, int m) {
    vector<int> nums;
    for (int a = n; a < m; a++)
        nums.push_back(0.5*a*(3*a-1));
    return nums;
}

vector<int> TPH::hexagonal(int n, int m) {
    vector<int> nums;
    for (int a = n; a < m; a++)
        nums.push_back(a*(2*a-1));
    return nums;
}

int TPH::main() {
    int n = 100000;
    vector<int> tri = triangular(285, n);
    vector<int> pent = pentagonal(165, n);
    vector<int> hex = hexagonal(143, n);
    // for (int num : tri) cout << num << endl;
    // cout << "End of triangulars \n";
    // for (int num : pent) cout << num << endl;
    // cout << "End of pentagonals \n";
    for (int num : hex) { // check containment of element in tri and pent
        if (find(tri.begin(), tri.end(), num) != tri.end() && find(pent.begin(), pent.end(), num) != pent.end()) cout << num << endl;
    }
    // cout << "End of hexagonals \n";
    
    return 0;
}
