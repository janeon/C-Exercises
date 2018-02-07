//
//  2048.hpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/26/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#ifndef _048_hpp
#define _048_hpp

#include <stdio.h>
class game2048 {
public:
    int inBoard[4][4];
    void print();
    void flushleft();
    void left();
    void flushup();
    void up();
    void flushright();
    void right();
    void flushdown();
    void down();
    int main();
};
#endif /* _048_hpp */
