//
//  minions.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/airconditioned
//  Created by Jane Hsieh on 1/16/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "minions.hpp"
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

vector <tuple<int,int>> minions::bsort(vector<tuple<int,int>> a, int s) {
    for (int i = 1; i < s; i++) {
        bool swapped = false;
        for (int j = 0; j < s - i; j++) {
            if (get<1>(a[j]) > get<1>(a[j+1])) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
    }
    // for (vector<tuple<int,int>>::iterator it = a.begin(); it != a.end(); it++) { tuple<int,int> temp =  *it; cout << get<0>(temp) << " " << get<1>(temp) << endl; }
    return a;
}
void minions::run() {
    vector<tuple<int,int>> myvec;
    int minions;
    cin >> minions;
    int first; int second;
    tuple<int, int> tmp;
    for (int i = 0; i < minions; i++) {
        cin >> first >> second;
        tmp = make_tuple(first,second);
        myvec.push_back(tmp);
    }
    myvec = bsort(myvec,myvec.size());
    //for (vector<tuple<int,int>>::iterator it = myvec.begin(); it != myvec.end(); it++) { tuple<int,int> temp =  *it; cout << get<0>(temp) << " " << get<1>(temp) << endl; }
    
    vector<int> rooms;
    int current = get<1>(myvec.at(0)); rooms.push_back(current);
    //cout << current << endl;
    
    for (vector<tuple<int,int>>::iterator it = myvec.begin(); it != myvec.end(); it++) {
        tuple<int,int> temp =  *it;
        //cout << get<0>(temp) << " " << get<1>(temp) << endl;
        if (current < get<0>(temp)) {
            current = get<1>(temp); rooms.push_back(get<1>(temp));
        }
    }
    cout << rooms.size() << endl;
    //for (vector<int>::iterator it = rooms.begin(); it != rooms.end(); it++) { cout << *it << endl; }
}
