//
//  Print3D.cpp
//  C++ Exercises
//
//  Created by Jane Hsieh on 1/11/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Print3D.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>

void Print3D::foo()
{
    double arg, output;
    std::cin >> arg;
    output = ceil(log2(arg)) + 1;
    printf ("%u", int(output));
}
