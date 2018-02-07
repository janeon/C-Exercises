//
//  listgame2.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/27/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "listgame2.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int listgame2::sum(int n){
    return 0.5*(n+1)*n;
}
bool listgame2::exists(vector<int> vec, int n){
    return find(vec.begin(), vec.end(), n) != vec.end();
}
std::string listgame2::privateEyesOnly(std::string message) {
    std::string output = ""; char updated;
    for (int i = 26; i > -27; i--) {
        bool readable = true;
        // cout << "i: " << i << endl;
        output = "";
        for (char letter: message) { // iterating through each letter to shift and append to output
            cout << "unupdated: " << int(letter) << " " << letter << endl;
            if (letter == ' ' || letter == ',' || letter == '.' || letter == '!' || letter == '?' || letter == '(' || letter == ')')
                updated = letter;
            else {
                updated = int(letter) + 9;
                int now = int(updated);
                if ((now >= 48 && now <= 57) || (now >= 65 && now <= 90) || (now >= 97 && now <= 122)) output = output;
                else {
                    cout << "breached " << now << endl;
                    readable = false; break;}
            }
            cout << "updated: " << int(updated) << " " << updated << endl;
            output = output + updated;
        }
        if (readable) {
            cout << output << endl;
            return output;
        }
    }
    // the shift needs to be circular, argghhhhhhhh
    cout << message << endl;
    cout << output << endl;
    return output;
}

int listgame2::main(){
    long f,n; cin >> n; set<int> factors; f = 2; map<int,int> repeats;
    while (f < n) {
        if (n%f == 0) {
            int size = factors.size();
            factors.insert(f); // try adding factor as new factor
            if (factors.size() == size) { // if factor already exists in set
                map<int,int> :: const_iterator it = repeats.find(f);
                (it != repeats.end()) ? repeats.at(f) ++ : repeats[f] = 2;
            }
            n /= f;
        }
        else {
            f++;
        }
    }
    if (n > 1) {
        factors.insert(n);
    }
    int count = factors.size() - repeats.size();
    // cout << count << endl;
    for (auto repeat:repeats) {
        int n = 1;
        while (sum(n) < repeat.second) n++;
        count += n-1;
        
    }
    // cout << sum(8) << endl;
    // cout << factors.size() << endl;
    // cout << repeats.size() << endl;
    cout << count<< endl;
    // for (int factor:factors) cout << factor << " " << endl;
    return 0;
}
