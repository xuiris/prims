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
#include <map>
using namespace std;

struct Minheap {
    vector<pair<int, int>> h; // pair: <key, node>
    map<int, int> index; // stores node and its index in the heap h
    int parent(int i);
    int left(int i);
    int right(int i);
    void swap(int a, int b);
    void percdown(int i);
    void percup(int i);
    void heapify();
    void printheap();
    void delmin();
    bool isempty();
    int minnode();
};

struct AdjList {
    map<int, map<int, int>> adj; // <node, <adjacent node, cost>>
    int firstcost(); // gives the min cost for edge connected to node 1
};

struct MST {
    vector<int> currnodes;
    void printmst();
};

MST prims(Minheap hp, AdjList al); //minheap contains all nodes with min as node1 and correct key, all other nodes key = inf
                                   //adjlist has all the nodes within the graph





#endif /* prims_hpp */
