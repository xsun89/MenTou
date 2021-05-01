//
// Created by Xin Sun on 2021-05-01.
//
#include <iostream>

using namespace std;

class UnionSet{
public:
    int *boss, n;
    UnionSet(int n) : n(n) {
        boss = new int[n + 1];
        for (int i = 0; i <= n; i++){
            boss[i] = i;
        }
    }

    int find(int x){
        if(boss[x] == x) return x;
        return find(boss[x]);
    }

    void merge(int a, int b){
        int ba = find(a);
        int bb = find(b);
        if(ba == bb) return;
        boss[bb] = ba;

        return;
    }
};

int main()
{

    return 0;
}