//  Computes possible ACM problems completed given time taken and penalty times
//  ACM.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/acm2
//  Created by Jane Hsieh on 1/16/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "ACM.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;
vector<int> ACM::bsort(vector<int> a, int s) {
    for (int i = 1; i < s; i++) {
        bool swapped = false;
        
        for (int j = 0; j < s - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
    }
    return a;
}

void ACM::run() {
    vector<int> myvec;
    int inputs, first; inputs = 0;
    cin >> inputs >> first;
    int tmp;
    for (int i = 0; i < inputs; i++) {
        cin >> tmp;
        myvec.push_back(tmp);
    }
    
    int AC = 1;
    int CT = myvec.at(first); myvec[first] = 1000;
    int PT = CT;
    if (CT > 300) {
        cout << 0 << " " << 0 << endl;
    }
    else {
        myvec = bsort(myvec, inputs);
        int MIN = myvec.at(0);
        while (MIN + CT <= 300) {
            myvec[0] = 1000;
            CT += MIN;
            PT += CT;
            AC++;
            myvec = bsort(myvec, inputs);
            MIN = myvec.at(0);
            //         min = *min_element(myvec.begin(), myvec.end());
            //        cout<<"Min value: "<<min<<endl;
        }

        cout << AC << " " << PT << endl;
    }
}

/*
 while (MIN + CT <= 300) { // if the completing the next problem does not run overtime
 if (first < 20) {  // if first problem has not already been completed
 if (myvec.at(first) > 300) { // if this first problem exceeds 300 mins, it can't be done
 cout << AC << endl << PT << endl; break;
 }
 else { // otherwise, do the problem and set it as done
 AC = 1; first = 20;
 PT = CT = myvec.at(first); myvec[first] = 1000;
 }
 }
 // cout << CT << endl;
 else { // if first problem is done
 sort(myvec.begin(), myvec.end());
 MIN = myvec.at(0); myvec[0] = 1000;
 CT += MIN;
 PT += CT;
 AC++;
 sort(myvec.begin(), myvec.end());
 MIN = myvec.at(0); myvec[0] = 1000;
 }
 
 }
 // cout << AC << endl << PT << endl;
 // cout << MIN;
 // for (vector<int>::iterator it = myvec.begin(); it != myvec.end(); it++) {cout << *it << endl;}
 //double min = *min_element(myvec.begin(), myvec.end());
 */

