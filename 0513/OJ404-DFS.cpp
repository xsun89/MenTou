//
// Created by Xin Sun on 2021-05-27.
//

#include <iostream>

using namespace std;

char mmap[3005][3005];
int ans[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, cnt = 1, a, b;

void func(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int x = sx + dir[i][0];
        int y = sy + dir[i][1];
        if (x <= 0 || y <= 0 || x > n || y > m || ans[x][y] != 0 || mmap[x][y] == mmap[sx][sy]) {
            continue;
        }
        cnt++;
        ans[x][y] += 1;
        func(x, y);
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    cin >> a >> b;
    ans[a][b] = 1;
    cnt = 1;
    func(a, b);
    cout << cnt << endl;

    return 0;
}