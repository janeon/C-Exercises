//
//  minions.hpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/16/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#ifndef minions_hpp
#define minions_hpp

#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;
class minions {
public:
    vector<tuple<int,int>> bsort(vector<tuple<int,int>> a, int s);
    void run();
};

#endif /* minions_hpp */
