//
// Created by Xin Sun on 2021-05-01.
//
#include <iostream>
using namespace std;

class UnionSet {
public:
    int *color, n;

    UnionSet(int n) : n(n) {
        color = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            color[i] = i;
        }
    }

    int find(int x) {
        return color[x];
    }

    void merge(int a, int b) {
        int cb = color[b];
        for (int i = 0; i <= n; i++) {
            if (color[i] == cb) {
                color[i] = color[a];
            }
        }
        return;
    }
};
