//
// Created by Xin Sun on 2021-05-28.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
  int x, y, step;
};

int n, m, check[150][150];
char mmap[150][150];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

void setData(int x, int y){
    check[x][y] = 2;
    for(int i = 0; i < 8; i++){
        for(int j = 1; 1; j++){
            int xx = x + dir[i][0] * j;
            int yy = y + dir[i][1] * j;
            if(mmap[xx][yy] != 'O'){
                break;
            }
            check[xx][yy] = 2;
        }
    }
}

void bfs(int x, int y){
    if(check[x][y] == 2){
        cout << 0 << endl;
        return;
    }
    queue<node> que;
    check[x][y] = 1;
    que.push((node){x, y, 0});
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];

            if(check[xx][yy] == 2){
                cout << temp.step + 1 << endl;
                return;
            }
            if(mmap[xx][yy] == 'O' && check[xx][yy] == 0){
                check[xx][yy] = 1;
                que.push((node){xx, yy, temp.step + 1});
            }
        }
    }
    cout << "Impossible!" << endl;
}

int init(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(!a){
        return 0;
    }
    memset(check, 0, sizeof(check));
    setData(a, b);
    bfs(c, d);
    return 1;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
        }
    }

    while(init()){
    }

    return 0;
}