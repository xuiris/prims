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

int Minheap::lft(int i) {
    return (2*i)+1;
}

int Minheap::rght(int i) {
    return (2*i)+2;
}

void Minheap::percdown(int i) {
    pair<int, int> temp;
    while ((rght(i) < h.size()) && ((h[i].first > h[lft(i)].first) || (h[i].first > h[rght(i)].first)))  {
        temp = h[i];
        if (h[lft(i)].first < h[rght(i)].first) {
            h[i] = h[lft(i)];
            h[lft(i)] = temp;
            i = lft(i);
        }
        else {
            h[i] = h[rght(i)];
            h[rght(i)] = temp;
            i = rght(i);
        }
    }
    if ((lft(i) < h.size()) && (h[i].first > h[lft(i)].first)) {
        temp = h[i];
        h[i] = h[lft(i)];
        h[lft(i)] = temp;
    }
    return;
}

void Minheap::percup(int i) {
    pair<int, int> temp = h[i];
    while ((h[i].first < h[parent(i)].first) && (i != -1)) {
        h[i] = h[parent(i)];
        h[parent(i)] = temp;
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
        h[0] = h[h.size()-1];
        h.erase(h.end()-1);
        percdown(0);
    }
}

