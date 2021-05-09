//
// Created by Xin Sun on 2021-05-05.
//
#include <iostream>
using namespace std;
int nmap[1000][1000];
int num[8] = {0, 1, 3, 9, 27, 81, 243, 729};

void func(int x, int y, int n){
    if(n == 1){
        nmap[x][y] = 1;
        return;
    }
    func(x, y, n - 1);
    func(x, y + 2 * num[n - 1], n - 1);
    func(x + num[n - 1], y + num[n - 1], n - 1);
    func(x + num[n - 1] * 2, y, n - 1);
    func(x + num[n - 1] * 2, y + 2 * num[n - 1], n - 1);

    return;

}
int main()
{
    func(0, 0, 7);
    int op;
    while (cin >> op){
        if (op == -1){
            break;
        }
        for(int i = 0; i < num[op]; i ++){
            for(int j = 0; j < num[op]; j ++){
                if(nmap[i][j] == 0){
                    cout << ' ';
                }else{
                    cout << 'X';
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
