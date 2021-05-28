//
// Created by Xin Sun on 2021-05-27.
//
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};
char mmap[3005][3005];
int ans[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, k, cnt;
queue<node> que;

void func(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int x = sx + dir[i][0];
        int y = sy + dir[i][1];
        if (x <= 0 || y <= 0 || x > n || y > m || ans[x][y] != 0 || mmap[x][y] == mmap[sx][sy]) {
            continue;
        }
        cnt++;
        ans[x][y] = 1;
        que.push((node){x, y});
        func(x, y);
    }
}

void save(){
    while(!que.empty()){
        node tmp = que.front();
        que.pop();
        ans[tmp.x][tmp.y] = cnt;
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if(ans[i][j] == 0){
                cnt = 1;
                que.push((node){i, j});
                ans[i][j] = 1;
                func(i, j);
                save();
            }
        }
    }
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }

    return 0;
}
