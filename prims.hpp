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
#include <set>
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

struct Graph {
    map<int, map<int, int>> adj; // Adjacency list <node, <adjacent node, cost>>
    map<int, pair<int, int>> edges; // all edges in graph <cost, <small node, big node>>
    int firstcost(); // gives the min cost for edge connected to node 1
};

struct MST {
    vector<pair<int,int>> mst_edges;
    set<int> currnodes;
    bool inmst(int i);
    void printmst();
};

MST prims(Minheap hp, Graph al); //minheap contains all nodes with min as node1 and correct key, all other nodes key = inf
                                   //adjlist has all the nodes within the graph



#endif /* prims_hpp */
