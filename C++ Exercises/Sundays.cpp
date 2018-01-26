//
//  Sundays.cpp
//  C++ Exercises
//  Solved :) https://projecteuler.net/problem=19
//  Created by Jane Hsieh on 1/24/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Sundays.hpp"
#include <iostream>
#include <vector>
using namespace std;
int Sundays::main(){
    int days = 1; int times = 0;
    vector<int> full_months = {4,6,9,11};
    for (int year = 1; year <= 100; year++) {
        for (int month = 1; month < 13; month++) {
            cout << " First of the " << month << " month of year " << year + 1900 << " was a ";
            switch (days % 7 + 1) {
                case 1:
                    cout << "Mon"; break;
                case 2:
                    cout << "Tues"; break;
                case 3:
                    cout << "Wednes"; break;
                case 4:
                    cout << "Thurs"; break;
                case 5:
                    cout << "Fri"; break;
                case 6:
                    cout << "Satur"; break;
                case 7:
                    cout << "Sun"; break;
                default:
                    cout << "Weird "; break;
            }
            cout << "day" << endl;
            if (days % 7 + 1 == 7) times++;
            if (year % 4 == 0 && month == 2)
                days += 29;
            else if (year % 4 != 0 && month == 2)
                days += 28;
            else if (find(full_months.begin(), full_months.end(), month) != full_months.end()) days += 30;
            else days += 31;
            
        }
    }
    cout << "A total of  " << times << " Mondays occurred on the first of the month in the 20th century." << endl;
    return 0;
}
