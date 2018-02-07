//
//  DataStructure.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/guessthedatastructure
//  Created by Jane Hsieh on 1/31/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//  Failed second case

#include "DataStructure.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector> // i.e. stack
#include <queue> // queue && priority queue
using namespace std;
vector<int> splitLine1(string line) {
    stringstream ss(line);
    istream_iterator<int> begin(ss);
    istream_iterator<int> end;
    vector<int> vec(begin, end);
    return vec;
}
bool stack1(vector<string> lines){
    vector<int> stack;
    // Iterating thru lines to perform bag commands
    for (string item:lines){
        int command, x, top; string sub, sub2;
        sub = item.substr(0,1); sub2 = item.substr(2,1);
        top = 0; // cout << sub << endl << sub2 << endl;
        command = stoi(sub); x = stoi(sub2);
        // CHECKING STACKNESS
        if (!stack.empty()) top = stack.at(stack.size()-1);
        (command == 1) ? stack.push_back(x) : stack.pop_back();
        if (command == 2 && top != x) return false;
    }
    return true;
}
bool queue1(vector<string> lines){
    queue<int> q;
    for (string item:lines){
        int command, x, first; string sub, sub2;
        sub = item.substr(0,1); sub2 = item.substr(2,1);
        command = stoi(sub); x = stoi(sub2); first = 0;
        // QNESS
        if (q.empty() && command == 2) return false;
        if (!q.empty()) first = q.front();
        (command == 1) ? q.push(x) : q.pop();
        if (command == 2 && first != x) return false;
    }
    return true;
}
bool priority_queue1(vector<string> lines){
    priority_queue<int> q;
    for (string item:lines){
        int command, x, first; string sub, sub2;
        sub = item.substr(0,1); sub2 = item.substr(2,1);
        command = stoi(sub); x = stoi(sub2); first = 0;
        // CHECKING PQNESS
        if (!q.empty()) first = q.top();
        (command == 1) ? q.push(x) : q.pop();
        if (command == 2 && first != x) return false;
    }
    return true;
}
int DataStructure::main(){
    string num, line; int n;
    while (getline(cin, num)) {
        n = stoi(num);
        vector<string> lines;
        // collecting lines
        for (int i = 0; i < n; i++) {
            getline(cin, line); lines.push_back(line);
        }
        // if (priority_queue1(lines)) cout << n << " true \n";
        // testing ds
        int trues = 0; int ds = 0;
        if (stack1(lines)) {trues++; ds = 1;}
        if (queue1(lines)) {trues++; ds = 2;}
        if (priority_queue1(lines)) {trues++; ds = 3;}
        // ending tests, beginning outputs
        // cout << num << " " << trues << endl;
        if (trues > 1) { cout << "not sure\n";}
        else {
            // suppose there's  0/1 possibility
            switch (ds) {
                case 0:
                    cout << "impossible "<< endl;
                    break;
                case 1:
                    cout << "stack " <<  endl;
                    break;
                case 2:
                    cout << "queue " <<  endl;
                    break;
                case 3:
                    cout << "priority queue " << endl;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
