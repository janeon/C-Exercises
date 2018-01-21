//
//  Coloring.cpp
//  C++ Exercises
//  Graph/vertex coloring!
//  https://open.kattis.com/problems/coloring
//  Created by Jane Hsieh on 1/21/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Coloring.hpp"
#include <iostream>
#include <vector>
using namespace std;
int Coloring::main(){
    vector<int> vertices; int numv, input; cin >> numv;
    for (int z = 0; z < numv; z++) { cin >> input;
        vertices.push_back(input);
    }
    return 0;
}
