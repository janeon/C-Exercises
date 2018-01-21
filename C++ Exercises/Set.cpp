//
//  Set.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/set
//  Created by Jane Hsieh on 1/20/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Set.hpp"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int Set::main(){
    vector<string> inputs;
    for (int i = 0; i < 12; i++){
        string input; cin >> input;
        inputs.push_back(input);
    }
    set<set<int>> Sets;
    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 12; b++) {
            for (int c = 0; c < 12; c++) {
                if (a==b || b==c || c==a)
                    ;
                else {
                string first = inputs.at(a); string second = inputs.at(b); string third = inputs.at(c);
                set<int> A = {}; set<char> B = {}; set<char> C ={}; set<char> D ={};
                A.insert(first[0]); B.insert(first[1]); C.insert(first[2]); D.insert(first[3]);
                A.insert(second[0]); B.insert(second[1]); C.insert(second[2]); D.insert(second[3]);
                A.insert(third[0]); B.insert(third[1]); C.insert(third[2]); D.insert(third[3]);
                    if (A.size() != 2 && B.size() != 2 && C.size() != 2 && D.size() != 2) {
                    set<int> str {a+1,b+1,c+1};
                    Sets.insert(str);
                    }
                }
            }
        }
    }
    for(auto it : Sets){
        set<int> group = it;
        for(int f : group)
            cout << f << " ";
        cout << endl;
    }
    if (Sets.empty())
        cout << "no sets";
    return 0;
}
