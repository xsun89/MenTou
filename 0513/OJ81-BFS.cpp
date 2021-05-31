//
// Created by Xin Sun on 2021-05-28.
//
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, step, f;
};

int n, m, checkWithoutPhone[2005][2005], checkWithPhone[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[2005][2005];

int main()
{
    cin >> n >> m;
    queue<node> que;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mmap[i][j];
            if(mmap[i][j] == 'S'){
                que.push((node){i, j, 0, 0});
                checkWithoutPhone[i][j] = 1;
            }
        }
    }

    while(!que.empty()){
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++){
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == 'T' && temp.f == 1){
                cout << temp.step + 1 << endl;
                return 0;
            }
            if(mmap[x][y] == 'P' && checkWithPhone[x][y] == 0){
                checkWithPhone[x][y] = 1;
                que.push((node){x, y, temp.step + 1, 1});
            }else if(mmap[x][y] == 'S' || mmap[x][y] == 'T' || mmap[x][y] == '.'){
                if(checkWithoutPhone[x][y] == 0 && temp.f == 0) {
                    checkWithoutPhone[x][y] = 1;
                    que.push((node) {x, y, temp.step + 1, 0});
                }else if(checkWithPhone[x][y] == 0 && temp.f == 1){
                    checkWithPhone[x][y] = 1;
                    que.push((node) {x, y, temp.step + 1, 1});
                }
            }

        }
    }

    return 0;
}