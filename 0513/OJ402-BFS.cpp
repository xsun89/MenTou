//
// Created by sunxi on 2021-06-01.
//
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int now, step;
};

int n, a, b, check[205];
int nums[205];

int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    check[a] = 1;
    queue<node> que;
    que.push((node){a, 0});
    while (!que.empty()){
        node tmp = que.front();
        que.pop();
        if(tmp.now == b){
            cout << tmp.step << endl;
            return 0;
        }

        int upNode = tmp.now + nums[tmp.now];
        int downNode = tmp.now - nums[tmp.now];
        if(upNode <= n && check[upNode] == 0){
            check[tmp.now] = 1;
            que.push((node){upNode, tmp.step + 1});
        }

        if(downNode > 0 && check[downNode] == 0){
            check[tmp.now] = 1;
            que.push((node){downNode, tmp.step + 1});
        }
    }

    cout << -1 << endl;
}
