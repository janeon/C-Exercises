//
//  Internet.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 2/2/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//  exceeds time limit

#include "Internet.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Internet::main(){
    string line; int N,M; // number of houses and cables
    scanf("%d %d", &N, &M); // cout << N << M;
    vector<bool> connected(N, false);
    connected.at(0) = 1; vector<pair<int, int>> cables;
    for (int i = 0; i < M; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;
//         cout << endl << a << ":" << connected.at(a) << "  " << b << ":" << connected.at(b) << "  " << connected.at(a) && !connected.at(b);
        cables.push_back(make_pair(a, b));
    }
    // while cables not all empty or all non-lit
    bool allUnLit = false; int numUnlit;
    while (!cables.empty() && !allUnLit) {
        numUnlit = 0; int orig = cables.size();
        for (int i = 0; i < cables.size(); i++) {
            auto cable = cables.at(i);
            int a = cable.first; int b = cable.second;
//            cout << "Passing cable " << " a = " << a << " b = " << b << endl;
            if (connected.at(a) && !connected.at(b)) connected.at(b) = 1;
            else if (connected.at(b) && !connected.at(a)) connected.at(a) = 1;
            if (connected.at(a) || connected.at(b)) cables.erase(cables.begin()+i);
//                cout << "erasing ab" << a << b << endl;
            else numUnlit++;
        }
//        for (bool c : connected) cout << c << " ";
        if (numUnlit == orig) allUnLit = true;
//        cout << " Post round "<< allUnLit << endl;
    }
    
    bool allConnected = true;
    for (int i = 0; i < N; i++) {
        if (!connected.at(i)) { cout << i+1 << endl; allConnected = false; }
    }
    if (allConnected) cout << "Connected\n";
    return 0;
}
