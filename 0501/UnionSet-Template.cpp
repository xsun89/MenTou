//
// Created by Xin Sun on 2021-05-01.
//
#include <iostream>
using namespace std;

class UnionSet{
public:
    int *fa, n;
    UnionSet(int n) : n(n) {
        fa = new int[n + 1];
        for (int i = 0; i <= n; i++){
            fa[i] = i;
        }
    }

    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b){
        fa[get(a)] =  get(b);
    }
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b, c;
    UnionSet u(n);
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1){
            u.merge(b, c);
        }
        if(a == 2){
            if(u.get(b) == u.get(c)){
                printf("Yes\n");
            }else {
                printf("No\n");
            }
        }
    }
}
