//
// Created by sunxi on 2021-04-27.
//
#include <iostream>
using namespace std;

int n, ans;
int main() {
    cin >> n;

    for(int i = 0; i <= n / 3; i++){
        for(int j = i; j <= (n - i) / 2; j++){
            int t = n - i -j;
            if(i + j > t){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
