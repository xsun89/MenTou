//
// Created by Xin Sun on 2021-05-26.
//
#include <iostream>
#include <queue>

using namespace std;
struct node {
    node(int x, int y, int step) : x(x), y(y), step(step) {}
    int x, y, step;
};

int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[505][505];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '2'){
                sx = i;
                sy = j;
            }
        }
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    while(!que.empty()){
        node tmp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if(mmap[x][y] == '3'){
                cout << tmp.step + 1 << endl;
                return 0;
            }
            if(mmap[x][y] == '.'){
                mmap[x][y] = 0;
                que.push((node){x, y, tmp.step + 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}