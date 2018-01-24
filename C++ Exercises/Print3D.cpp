//  Finds the number of days needed to print a certain number of statues given 3D printers that can self-reproduce
//  Print3D.cpp
//  C++ Exercises
//  https://open.kattis.com/problems/3dprinter
//  Created by Jane Hsieh on 1/11/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Print3D.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>

void Print3D::count()
{
    double arg, output;
    std::cin >> arg;
    output = ceil(log2(arg)) + 1;
    printf ("%u", int(output));
}
