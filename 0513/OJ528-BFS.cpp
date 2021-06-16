//
// Created by sunxi on 2021-06-02.
//
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int num, step;
};

int n, x, y, check[105], nums[105][105];

int main() {
    cin >> n >> x >> y;
    queue<node> que;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> nums[i][j];
        }
    }

    que.push((node){x, 0});
    check[x] = 1;
    while (!que.empty()){
        node tmp = que.front();
        que.pop();
        if(tmp.num == y){
            cout << tmp.step - 1 << endl;
            return 0;
        }
        for(int i = 1; i <= n; i++){
            if(nums[tmp.num][i] == 1 && check[i] == 0){
                check[i] = 1;
                que.push(node{i, tmp.step + 1});
            }
        }
    }
    cout << 0 << endl;
    return 0;
}