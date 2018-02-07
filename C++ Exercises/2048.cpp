//
//  2048.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/26/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "2048.hpp"
#include <iostream>
using namespace std;

void game2048::print() {
    for (int R = 0; R < 4; R++) {
        for (int C = 0; C < 4; C++)
            cout << inBoard[R][C] << " ";
        cout << endl;
    }
}
void game2048::flushleft(){
    for (int row = 0; row < 4; row++) {
        for (int col = 3; col > 0; col--) {
            if (inBoard[row][col-1] == 0 && inBoard[row][col] != 0) swap(inBoard[row][col], inBoard[row][col-1]) ;
        }
    }
    // print();
}
void game2048::left(){
    // flush left without merging
    for (int y = 0 ; y < 3; y++) flushleft();
    // merging
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (inBoard[row][col] == inBoard[row][col+1] ) {
                inBoard[row][col] *= 2; inBoard[row][col+1] = 0;
            }
        }
    }
    for (int y = 0 ; y < 3; y++) flushleft();
    print();
}
void game2048::flushup(){
    for (int col = 0; col < 4; col++) {
        for (int row = 1; row < 4; row++) {
            if (inBoard[row-1][col] == 0 && inBoard[row][col] != 0) swap(inBoard[row-1][col], inBoard[row][col]) ;
        }
    }
    // print();
}
void game2048::up(){
    for (int y = 0 ; y < 3; y++) flushup();
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            if (inBoard[row][col] == inBoard[row+1][col] ) {
                inBoard[row][col] *= 2; inBoard[row+1][col] = 0;
            }
        }
    }
    for (int y = 0 ; y < 3; y++) flushup();
    print();
}
void game2048::flushright(){
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (inBoard[row][col+1] == 0 && inBoard[row][col] != 0) swap(inBoard[row][col], inBoard[row][col+1]) ;
        }
    }
    // print();
}
void game2048::right(){
    for (int y = 0 ; y < 3; y++) flushright();
    for (int row = 0; row < 4; row++) {
        for (int col = 3; col > 0; col--) {
            if (inBoard[row][col] == inBoard[row][col-1] ) {
                inBoard[row][col] *= 2; inBoard[row][col-1] = 0;
            }
        }
    }
    for (int y = 0 ; y < 3; y++) flushright();
    print();
}
void game2048::flushdown(){
    for (int col = 0; col < 4; col++) {
        for (int row = 2; row >= 0; row--) {
            if (inBoard[row+1][col] == 0 && inBoard[row][col] != 0) swap(inBoard[row+1][col], inBoard[row][col]) ;
        }
    }
    // print();
}
void game2048::down(){
    for (int y = 0 ; y < 3; y++) flushdown();
    for (int col = 0; col < 4; col++) {
        for (int row = 3; row > 0; row--) {
            if (inBoard[row][col] == inBoard[row-1][col] ) {
                inBoard[row][col] *= 2; inBoard[row-1][col] = 0;
            }
        }
    }
    for (int y = 0 ; y < 3; y++) flushdown();
    print();
}

int game2048::main(){
    int row, col, move;
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++)
            cin >> inBoard[row][col];
    }
    cin >> move; // 0, 1, 2, or 3 denotes a left, up, right, or down, respectively
    // print(inBoard, 4, 4);
    switch (move) {
        case 0:
            left(); break;
        case 1:
            up(); break;
        case 2:
            right(); break;
        case 3:
            down(); break;
        default: break;
    }
    return 0;
}
