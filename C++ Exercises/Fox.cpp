//
//  Fox.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/31/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Fox.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <iterator>
using namespace std;
vector<string> Fox::splitLine(string line) {
    stringstream ss(line);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    // copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(cout, "\n"));
    return vstrings;
}
bool contains(vector<string> a, string b){
    return find(a.begin(), a.end(), b) != a.end();
}
int Fox::main() {
    string cases; getline(cin, cases); int test = stoi(cases); vector<string> outputs;
    string line, sound, token;
    // getting sounds
    for (int i = 0; i < test; i++) {
        // getting recording
        vector<string> sounds; vector<string> recording; getline(cin, line); recording = splitLine(line);
        getline(cin, line); vector<string> tokens = splitLine(line);
        // cout << line << endl;
        while (tokens.at(1) == "goes") {
            // cout << tokens.at(2) << " truth " << (tokens.at(1) == "goes") << endl;
            sounds.push_back(tokens.at(2));
            getline(cin, line); tokens = splitLine(line);
        }
        string output = "";
        for (auto item : recording) {
            if (!contains(sounds, item)) output += (item + " ");
        }
        outputs.push_back(output);
    }
    for (string out:outputs) cout << out << endl;
    return 0;
}
