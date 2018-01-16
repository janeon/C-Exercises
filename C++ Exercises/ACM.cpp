//
//  ACM.cpp
//  C++ Exercises
//
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

