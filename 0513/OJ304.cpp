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
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
char mmap[200][200];

int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 'K'){
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
        for(int i = 0; i < 8; i++){
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if(x < 1 || y < 1 || x > n || y > m) continue;
            if(mmap[x][y] == 'H'){
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
