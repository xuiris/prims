//
//  main.cpp
//  prims
//
//  Created by Iris Xu on 12/11/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
        std::stringstream ss(line);
        std::string command;
        ss >> command;
        // put integers into a vector
        std::vector<pair<int, int> v = {};
        if (command == "MINHEAP") {
            for(std::string num; ss >> num;) {
                int n = stoi(num);
                pair<int, int> node (n, 0);
                v.push_back(node);
            }
            Minheap heap;
            heap.h = v;
            heap.printheap();
            heap.percdown(heap.h.size()/2);
            heap.printheap();
        }
    }
                
