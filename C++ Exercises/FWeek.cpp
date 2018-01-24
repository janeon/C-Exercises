//  Another Frosh Week Problem, harder this time
//  FWeek.cpp
//  C++ Exercises
//  Finds the min number of swaps needed to sort a list
//  https://open.kattis.com/problems/froshweek
//  Created by Jane Hsieh on 1/21/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
// Did not pass second sample case due to time limit :(

#include "FWeek.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
/*
int FWeek::main(){
    int num; cin >> num;
    vector<tuple<int,int>> arr;
    for (int i = 0; i < num; i++) { int input; cin >> input;
        arr.push_back(make_tuple(input,i));
    }
    sort(arr.begin(),arr.end()); // Unfortunately this is not allowed in Kattis submission
    for (auto it:arr) cout << get<0>(it)<< endl;
    vector<bool> visited(num,false);
    int node; int swaps = 0;
    for (int j = 0; j < arr.size(); j++) {
        int element = get<0>(arr[j]); int position = get<1>(arr[j]);
        if (visited[j] || (j == position)) {
            continue;
        }
        node = j; int cycle = 0;
        while (!visited[node]) {
            // cout << element << node << endl;
            visited[node] = true;
            node = get<1>(arr[node]);
            cycle ++;
        }
        swaps += cycle;
    }
    cout << swaps;
    return 0;
}

    for (auto pos:arr) {
        for (int toSwap = 0; int < arr.size(); toSwap++) {
            if ()
        }
    } */
    /*
    
    vector<int> inputs; int elements, input; cin >> elements;
    for (int i = 0; i < elements; i++) {
        cin >> input; inputs.push_back(input);
    }
    
    vector<tuple<int,int>> map; int current = 0;
    for (int i = 0; i < elements-1; i++) {
        if (inputs.at(i+1) < inputs.at(i)) {
            map.push_back(make_tuple(current, i+1)); current = i+1;
        }
    }
    
    if (current != elements)
        map.push_back(make_tuple(current,elements));
    if (map.size() == 1) {
        cout << 0; return 0;
    }
    // cout << "Map size: " << map.size();
    int subgraphs = 0; int total = 0;
    for (tuple<int,int> tup : map) {
        int begin = get<1>(tup); int end = get<0>(tup);
        int size =  begin - end; // cout << "Begin: " << begin << "End: " << end << endl;
        if  (size > 1) {
            subgraphs++; total += size;
        }
    }
    // cout << "Subgraphs: " << subgraphs;
    cout << total - subgraphs;
    return 0;
} */
