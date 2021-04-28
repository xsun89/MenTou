//
// Created by sunxi on 2021-04-27.
//
#include <iostream>
using namespace std;
int n, o[100005], w[100005], ans;
char s[100005];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i] == 'C'){
            o[i] = 1;
        }
        if(s[i] == 'W'){
            w[i] = 1;
        }
    }

    for (int i = 0; i < n; i++){
        o[i] += o[i - 1];
    }

    for(int i = n - 2; i >= 0; i--){
        w[i] += w[i + 1];
    }

    for(int i = 0; i < n; i++){
        if(s[i] == 'O'){
            ans += o[i] * w[i];
        }
    }

    cout << ans << endl;
    return 0;
}