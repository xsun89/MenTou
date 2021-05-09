//
// Created by Xin Sun on 2021-05-06.
//                             ()
//                  1               2               3
//        2        3      4       3     4            4
//   3    4  5   4   5    5     4   5    5           5
//
#include <iostream>
using namespace std;
int n, m, num[15];
int cnt = 1, l;
void p(){
    for(int i = 1; i <= m; i++){
       if(i != 1){
           cout << " ";
       }
       cout << num[i];
    }
    cout << endl;
}
void func(int s){
    if(l == 0){
        p();
        return;
    }
    for(int i = s; i <= n; i++){
        num[cnt] = i;
        cnt++;
        l--;
        func(i + 1);
        cnt--;
        l++;
    }
}
int main() {
    cin >> n >> m;
    l = m;
    func(1);
    return 0;
}