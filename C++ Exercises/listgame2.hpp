//
//  listgame2.hpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/27/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#ifndef listgame2_hpp
#define listgame2_hpp
#include <string>
#include <stdio.h>
#include <vector>
class listgame2 {
public:
    bool exists(std::vector<int> vec, int n);
    std::string privateEyesOnly(std::string input); // attempt at codefights challenge
    // https://codefights.com/challenge/ZmwS44X2LZLePZNQj/solutions/5XznmmN22ynCKrkbL
    int sum(int n);
    int main();
};
#endif /* listgame2_hpp */
