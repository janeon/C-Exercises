//  Finds the shortest root of a multigram, contains subroutines to find factors (both prime and nonprime)
//  Multigram.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/multigram
//  Created by Jane Hsieh on 1/17/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.

#include "Multigram.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> Multigram::primes(int n) {
    vector<int> factors;
    for(int i = 1; i < n; ++i)
    {
        if(n % i == 0)
            factors.push_back(i);
    } return factors;
    /* finds prime factors
     while (f*f < n) {
        if (n%f == 0) {
            factors.push_back(f);
            n /= f;
        }
        else {
            f++;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
     */
    return factors;
}

void Multigram::run(){
    string word; cin >> word;
    string s(word); bool same = false;
    vector<char> v(s.begin(), s.end());
    // sort(v.begin(), v.end());
    // for (vector<char>::iterator it = v.begin(); it != v.end(); it++) { cout << *it; }
    vector <int> factors = primes(word.length());
    int numFactors = factors.size();
    
    for (int i = 0; i < numFactors; i++) {
        string substr0 = word.substr(0,factors.at(i));// cout << endl << "substring is: " << substr0 << " " << factors.at(i) << endl;
        vector<char> vec(substr0.begin(),substr0.end());
        sort(vec.begin(), vec.end());
        string substr(vec.begin(),vec.end());
        int num = int(word.length()/factors.at(i));
        vector<string> substrings;
        for (int j = 0; j < num; j++) {
            vector<char>::const_iterator first = v.begin() + j * factors.at(i);
            vector<char>::const_iterator last = v.begin() + (j+1) * factors.at(i);
            vector<char> newVec(first, last);
            string substring(newVec.begin(),newVec.end()); // cout << "original " << substring;
            // for (vector<char>::iterator it = newVec.begin(); it != newVec.end(); it++) { cout << *it << " "; }
            sort(newVec.begin(), newVec.end());
            string substring2(newVec.begin(),newVec.end()); // cout << " new " << substring2;
            // for (vector<char>::iterator it = newVec.begin(); it != newVec.end(); it++) { cout << *it << " ";}
            substrings.push_back(substring2);
            //cout << endl;
        }
        same = true;
        for (int k = 0; k < substrings.size(); k++) {
            // cout << substrings.at(k) <<endl;
            if (substr != substrings.at(k)) same = false;
                //cout << "Not true between " << substr << " and " << substrings.at(k) << endl;
        }
        if (same) cout << substr0; break;
    }
    if (!same) cout << -1;
}








