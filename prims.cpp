//
//  prims.cpp
//  prims
//
//  Created by Iris Xu on 12/11/17.
//  Copyright © 2017 Iris Xu. All rights reserved.
//

#include "prims.hpp"

int Minheap::parent(int i) {
    int x = (i-1)/2;
    if (x < 0) {
        return x;
    }
    else return -1;
}

int Minheap::left(int i) {
    int x = (2*i)+1;
    if (x < h.size()) {
        return x;
    }
    else return -1;
}

int Minheap::right(int i) {
    int x = (2*1)+2;
    if (x < h.size()) {
        return x;
    }
    else return -1;
}

void Minheap::percdown(int i) {
    pair<int, int> temp;
    while ((right(i) != -1) && ((h[i].first > h[left(i)].first) || (h[i].first > h[right(i)].first)))  {
        temp = h[i];
        if (h[left(i)].first < h[right(i)].first) {
            h[i] = h[left(i)];
            h[left(i)] = temp;
            i = left(i);
        }
        else {
            h[i] = h[right(i)];
            h[right(i)] = temp;
            i = right(i);
        }
    }
    if ((left(i) != -1) && (h[i].first > h[left(i)].first)) {
        temp = h[i];
        h[i] = h[left(i)];
        h[left(i)] = temp;
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
    int i = h.size()/2;
    for (int i = h.size()/2; i >= 0; i--) {
        percdown(i);
    }
}

void Minheap::printheap() {
    for (int i = 0; i < h.size(); i++) {
        cout << h[i].first << " ";
    }
    cout << endl;
}

