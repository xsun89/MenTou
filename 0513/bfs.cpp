//
// Created by Xin Sun on 2021-05-26.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct node {
  int x, y, step;
};

int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0 -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }

    return 0;
}