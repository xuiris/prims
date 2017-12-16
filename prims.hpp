//
//  prims.hpp
//  prims
//
//  Created by Iris Xu on 12/11/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#ifndef prims_hpp
#define prims_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct Minheap {
    vector<pair<int, int>> h; // pair: <key, node>
    int parent(int i);
    int left(int i);
    int right(int i);
    void percdown(int i);
    void percup(int i);
    void heapify();
    void printheap();
};



#endif /* prims_hpp */
