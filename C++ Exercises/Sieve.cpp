//
//  Sieve.cpp
//  C++ Exercises
//  Implemeting the Sieve of Eratosthenes
//  And then trying to solve prime pair sets --> https://projecteuler.net/problem=60
//  Created by Jane Hsieh on 1/24/18.
//  Copyright © 2018 Jane Hsieh. All rights reserved.
//

#include "Sieve.hpp"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Sieve::main(){
    int input = 10000000;
    vector<bool> isPrime(input,true); vector<int> primes;
    isPrime[0] = false; isPrime[1] = false;
    
    for (int i = 0; i < sqrt(input); i++) {
        if (isPrime[i]) {
            for (int j = 0; pow(i, 2) + j*i < input; j++)
                isPrime[pow(i, 2) + j*i] = false;
        }
    }
    for (int it = 0; it < input; it++) {
        if (isPrime[it]) primes.push_back(it);
    }
    
    vector<int> pairs; int sum = 3; string concat, concat2;
    // for (int k = 1; k < 8; k++) {
    int begin = 2; int current = begin;
    pairs.push_back(primes.at(begin));
    
    while (pairs.size() < 2) {
        bool works = true;
        for (int a = 0; a < pairs.size(); a++){ // checks that current prime form pairs with all existing elements in list
            concat = to_string(pairs.at(a)) + to_string(primes.at(current));
            concat2 = to_string(primes.at(current)) + to_string(pairs.at(a));
            // cout << concat << " " << concat2 << endl;
            int check = stoi(concat); int check2 = stoi(concat2);
            if (isPrime[check] == false || false == isPrime[check2]) works = false;
        }
        if (works) {
            pairs.push_back(primes.at(current)); sum += primes.at(current);
            cout << concat << " " << concat2 << endl;
        }
        current++;
        // }
        for (auto p:pairs) cout << p << endl;
        pairs.clear();
    }
    
    //cout << sum;
    return 0;
}
