//
// Created by Xin Sun on 2021-05-28.
//
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, step, d;
};
int n, m, d, check[105][105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

char mmap[105][105];

int main(){
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++){
        cin >> &mmap[i][1];
    }

    queue<node> que;
    que.push((node){1, 1, 0, d});
    for(int i = 0; i <= d; i++){
        check[1][1][d] = 1;
    }

    while(!que.empty()){
        node tmp = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            for(int j = 2; j <= tmp.d; j++){
                int x = tmp.x + dir[i][0] * j;
                int y = tmp.y + dir[i][1] * j;
                if(mmap[x][y] == 0) break;
                if(x == n && y == m){
                    cout << tmp.step + 1 << endl;
                    return 0;
                }
                if(mmap[x][y] == 'P' && check[x][y][tmp.d - j] == 0){
                    check[x][y][tmp.d - j] = 1;
                    que.push((node){x, y, tmp.step + 1, tmp.d - j});
                }
            }

            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if(x == n && y == m){
                cout << tmp.step + 1 << endl;
                return 0;
            }

            if(mmap[x][y] == 'P' && check[x][y][tmp.d] == 0){
                check[x][y][tmp.d] = 1;
                que.push((node){x, y, tmp.step + 1, tmp.d});
            }
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
