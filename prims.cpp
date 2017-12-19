//
//  prims.cpp
//  prims
//
//  Created by Iris Xu on 12/11/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#include "prims.hpp"

int Minheap::parent(int i) {
    return (i-1)/2;
}

int Minheap::left(int i) {
    return (2*i)+1;
}

int Minheap::right(int i) {
    return (2*i)+2;
}

void Minheap::swap(int a, int b) {
    //swap
    pair<int, int> temp = h[a];
    h[a] = h[b];
    h[b] = temp;
    //update index
    index[h[a].second] = a;
    index[h[b].second] = b;
}

void Minheap::percdown(int i) {
    while ((right(i) < h.size()) && ((h[i].first > h[left(i)].first) || (h[i].first > h[right(i)].first)))  {
        if (h[left(i)].first < h[right(i)].first) {
            swap(i, left(i));
            i = left(i);
        }
        else {
            swap(i, right(i));
            i = right(i);
        }
    }
    if ((left(i) < h.size()) && (h[i].first > h[left(i)].first)) {
        swap(i, left(i));
    }
    return;
}

void Minheap::percup(int i) {
    pair<int, int> temp = h[i];
    while ((h[i].first < h[parent(i)].first) && (i != -1)) {
        swap(i, parent(i));
        i = parent(i);
    }
    return;
}

void Minheap::heapify() {
    for (int i = (h.size())/2; i >= 0; i--) {
        percdown(i);
    }
}

void Minheap::printheap() {
    for (int i = 0; i < h.size(); i++) {
        cout << h[i].first << " ";
    }
}

void Minheap::delmin() {
    if (h.size() == 1) {
        h.clear();
    }
    else {
        swap(0, h.size()-1);
        index.erase(h[h.size()-1].second); //delete index from index list
        h.erase(h.end()-1);
        percdown(0);
    }
}

bool Minheap::isempty() {
    if (h.size() == 0) {
        return true;
    }
    else return false;
}
             
int Graph::firstcost() {
    std::map<int, int>::iterator it = adj[1].begin();
    int min = it->second;
    for (it = it++; it != adj[1].end(); ++it) {
        if (it->second < min) {
            min = it->second;
        }
    }
    return min;
}
             
void MST::printmst() {
    for (std::vector<pair<int,int>>::const_iterator i = mst_edges.begin(); i != mst_edges.end(); ++i) {
        cout << i->first << " " << i->second << " ";
    }
}

MST prims(Minheap hp, Graph gr) {
    MST tree;
    while (hp.isempty() == false) {
        hp.heapify();
        // put min of heap into tree
        pair<int,int> minedge = gr.edges[hp.h[0].first];
        tree.mst_edges.push_back(minedge);
        // delete min
        hp.delmin();
        // update the key in the heap for nodes adjacent to deleted min
        std::map<int, int>::iterator it;
        int node, cost;
        for (it = gr.adj[min].begin(); it != gr.adj[min].end(); ++it) {
            node = it->first;
            cost = it->second;
            // change key to new cost only if old cost was larger
            if (hp.h[hp.index[node]].first > cost) {
                hp.h[hp.index[node]].first = cost;
            }
        }
    }
    return tree;
}


