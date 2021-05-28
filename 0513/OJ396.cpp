//
// Created by Xin Sun on 2021-05-26.
//

#include <iostream>
#include <queue>

using namespace std;
struct node {
    int x, y;
};

int n;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int mmap[50][50];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node> que;
    que.push((node){0, 0});
    mmap[0][0] = 3;
    while(!que.empty()){
        node tmp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if(x < 0 || y < 0 || x > n + 1 || y > n + 1 || mmap[x][y] != 0) {
                continue;
            }
            mmap[x][y] = 3;
            que.push((node){x, y});
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j != 1) cout << " ";
            if(mmap[i][j] == 0){
                cout << 2;
            }else if(mmap[i][j] == 1){
                cout << 1;
            }else{
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}