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
#include "prims.hpp"
#include <limits>
using namespace std;

int main(int argc, char* argv[]) {
    for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
        std::stringstream ss(line);
        std::string command;
        ss >> command;
        // put integers into a vector
        std::vector<pair<int, int>> v = {};
        if (command == "MINHEAP") {
            for(std::string num; ss >> num;) {
                int n = stoi(num);
                pair<int, int> node (n, 0);
                v.push_back(node);
            }
            Minheap heap;
            heap.h = v;
            heap.percdown(heap.h.size()/2);
            heap.printheap();
            cout << endl;
            heap.heapify();
            heap.printheap();
            cout << endl;
            heap.delmin();
            heap.delmin();
            heap.delmin();
            heap.printheap();
            cout<< endl;
        }
        if (command == "PRIM") {
            Minheap heap;
            AdjList alist;
            // put all the triples (node node cost) into adjlists and heap
            for(string frm, to, cost; ss >> frm >> to >> cost;) {
                int f = stoi(frm);
                int t = stoi(to);
                int c = stoi(cost);
                // add to heap: (check if the node exists yet in the adj list)
                if (alist.adj.count(f) == 0) {
                    if (f == 1) {
                        heap.h.push_back(make_pair(0,1));
                    }
                    else {
                        heap.h.push_back(make_pair(std::numeric_limits<int>::max(), f));
                    }
                    heap.index[f] = heap.h.size()-1; // keep track of indexing
                }
                if (alist.adj.count(t) == 0) {
                    if (t == 1) {
                        heap.h.push_back(make_pair(0,1));
                    }
                    else {
                        heap.h.push_back(make_pair(std::numeric_limits<int>::max(), t));
                    }
                    heap.index[t] = heap.h.size()-1; // keep track of indexing
                }
                // add to adj list:
                alist.adj[f][t] = c;
                alist.adj[t][f] = c;
            }
            cout << alist.firstcost() << endl;
            MST mytree = prims(heap, alist);
            mytree.printmst();
            cout << endl;
        }
    }
}
               
