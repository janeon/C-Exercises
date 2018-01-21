//
//  Frosh.cpp
//  C++ Exercises
//  It's a greedy ALG :D :D :D
//  https://open.kattis.com/problems/froshweek2
//  Created by Jane Hsieh on 1/20/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Frosh.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Frosh::main(){
    int m,n,input; cin >> m >> n; vector<int> tasks; vector<int> intervals;
    for (int x = 0; x < m; x++) {
        cin >> input;
        tasks.push_back(input);
    }
    for (int y = 0; y < n; y++) {
        cin >> input;
        intervals.push_back(input);
    }
    sort (tasks.begin(), tasks.end());
    sort (intervals.begin(), intervals.end());
    /*
    for (auto task: tasks)
        cout << task << " ";
    cout << endl;
    
    for (auto interval: intervals)
        cout << interval << " ";
    cout << endl;
    */
    int a,b,c; a = b = c = 0;
    while (a < m && b < n) {
        if (tasks.at(a) <= intervals.at(b)) {
            // cout << "task: " << a << " interval: " << b << " count: " << c << " complete " <<endl;
            a++; b++; c++;
        }
        else {
            // cout << "task: " << a << " interval: " << b << " count: " << c << " incomplete " << endl;
            b++;
        }
    }
    cout << c;
    return 0;
}



