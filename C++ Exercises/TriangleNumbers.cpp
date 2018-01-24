//
//  TriangleNumbers.cpp
//  C++ Exercises
//  #42 of Project Euler, Coded Triangle Numbers
//  Created by Jane Hsieh on 1/23/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "TriangleNumbers.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int TriangleNumbers::main(){
    ifstream stream1("words.txt"); string line; int max_word = 0; vector<int> wValues;
    if(!stream1)
        cout << "While opening a file an error is encountered" << endl;
    // file and words parsing
    while (getline(stream1, line)) {
        // splitting line of inputs to words and storing in words vector
        char delim = ','; vector<string> split(const string &line, char delim); stringstream ss1(line);
        string item; vector<string> words;
        while (getline(ss1, item, delim)) {
            item = item.substr(1, item.size()-2);
            int wordValue = 0;
            for (char letter:item)
                wordValue += letter - 'a' + 33;
                // cout << letter << " Letter value is: " << letter - 'a' + 33 << endl;
            words.push_back(item); wValues.push_back(wordValue);
            if (wordValue > max_word) max_word = wordValue;
            cout << item << " Word value is: " << wordValue << endl;
            }
    }
    // getting triangle numbers
    vector<int> triangle_nums; int n = 1; int tNum = 0;
    while (tNum < max_word) {
        tNum = (n + 1) * n * 0.5; triangle_nums.push_back(tNum);
        cout << n << "th triangle number is: " <<tNum << endl;
        n++;
    }
    int tWords = 0;
    // Finding triangle words
    for (int wVal : wValues) {
        if(find(triangle_nums.begin(), triangle_nums.end(), wVal) != triangle_nums.end()) tWords++;
        }
    cout << tWords;
    return(0);
}
    
