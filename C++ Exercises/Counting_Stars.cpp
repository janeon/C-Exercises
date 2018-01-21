//
//  Counting_Stars.cpp
//  C++ Exercises
//  PS: This solution did not pass all test cases
//  PSS: CHOOSE PROBLEMS WITH MULTIPLE TEST CASES IN THE FUTURE
//  https://open.kattis.com/problems/countingstars
//  Created by Jane Hsieh on 1/18/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Counting_Stars.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

int Counting_Stars::test(){
    int m,n, l, o; char star = '-'; o = 0;
    // while(scanf("%d" , &l) != EOF) {
    while (cin >> m >> n) {
        o++; cout << "Case " << o << ": ";
        string prev = ""; for (int a = 0; a < n; a++) { prev += "#";} string empty = prev;
        string line;
        int count = 0;
        vector<string> lines = {}; lines.push_back(empty);
        for (int y = 0; y < m; y++) {
            cin >> line; // cout << endl << line;
            lines.push_back(line);
        }
        lines.push_back(empty); string next;
        for (int i = 1; i < m; i++) {
            prev = lines.at(i-1);
            line = lines.at(i);
            next = lines.at(i+1);
            for (int x = 0; x < n; x++) {
                char current = line[x];
                if (line[x] == star) {
                    //cout << y << '-' << x << endl;
                    if (prev[x] != star && prev[x+1] != star && line[x-1] != star) {
                        count ++;
                        // cout << i << "new" << x << endl;
                    }
                }
                // cout << "prev:" << prev << endl << "current" << current << endl << "next" << next << endl;
                // cout << "processing line " << x << endl;
            }
            prev = line;
        }
        cout << count << endl;
}
    return 0;
}
int Counting_Stars::main(){
    int m,n,o; char star = '-'; o = 0;
        // o++; cout << "Case" << o;
        cin >> m >> n; string prev = ""; string line; // cout << endl << m << " " << n;
        for (int a = 0; a < n; a++) {
            prev += "#";
        }
        int count = 0;
        for (int y = 0; y < m; y++) {
            cin >> line; // cout << endl << line;
            for (int x = 0; x <= n; x++) {
                char current = line[x];
                if (line[x] == star) {
                    //cout << y << '-' << x << endl;
                    if (prev[x] != star && prev[x+1] != star && line[x-1] != star)  {
                        count ++;
                        cout << y << "new" << x << endl;
                    }
                }
            }
            prev = line;
        }
    cout << count;
    return 0;
}
/*
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n, l, o; char star = '-'; o = 0;
    while(scanf("%d" , &l) != EOF) {
        o++; cout << "Case" << o;
        cin >> m >> n; string prev = ""; string line; // cout << endl << m << " " << n;
        for (int a = 0; a < n; a++) {
            prev += "#";
        }
        int count = 0;
        for (int y = 0; y < m; y++) {
            cin >> line; // cout << endl << line;
            for (int x = 0; x < n; x++) {
                char current = line[x];
                if (line[x] == star) {
                    //cout << y << '-' << x << endl;
                    if (prev[x-1] != star && prev[x] != star && prev[x+1] != star && line[x-1] != star)  {
                        count ++;
                        cout << y << "new" << x << endl;
                    }
                }
            }
            prev = line;
        }
        cout << "count is" << count;
    }
    return 0;
}
*/
