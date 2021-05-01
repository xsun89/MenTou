//
// Created by Xin Sun on 2021-05-01.
//
//
// Created by Xin Sun on 2021-05-01.
//
#include <iostream>

using namespace std;

class UnionSet{
public:
    int *boss, *size, n;
    UnionSet(int n) : n(n) {
        boss = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++){
            boss[i] = i;
            size[i] = 1;
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
        if(size[ba] > size[bb]) {
            boss[bb] = ba;
            size[ba] += size[bb];
        }else{
            boss[ba] = bb;
            size[bb] += size[ba];
        }
        return;
    }
};

int main()
{

    return 0;
}
