//
// Created by Xin Sun on 2021-05-05.
//
#include <iostream>
using namespace std;
int n, num[15];
void p(int cnt){
    for(int j = 1; j <= cnt; j++){
        if(j != 1) cout << " ";
        cout << num[j];
    }
    cout << endl;

    return;
}
void func(int t, int cnt){
    for(int i = t; i <= n; i++){
        num[cnt] = i;
        p(cnt);
        func(i + 1, cnt + 1);
    }
}
int main()
{
    cin >> n;
    func(1, 1);
    return 0;
}