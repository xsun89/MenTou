//
// Created by Xin Sun on 2021-05-27.
//
#include <iostream>

using namespace std;

char mmap[2005][2005];
int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m, ans;

void func(int x, int y){
    for(int i = 0; i < 8; i++){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(mmap[xx][yy] == '#'){
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mmap[i][j] == '#'){
                ans++;
                mmap[i][j] = 0;
                func(i, j);
            }
        }
    }

    cout << ans << endl;
}