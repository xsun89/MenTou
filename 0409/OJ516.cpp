//
// Created by sunxi on 2021-04-27.
//
#include <iostream>
using namespace std;
long long n, numc[100005], numw[100005], ans;
char s[100005];

int main() {
    cin >> n >> &s[1];

    for (int i = 1; i <= n; i++){
        if(s[i] == 'C'){
            numc[i] = numc[i - 1] + 1;
        }else{
            numc[i] = numc[i - 1];
        }
    }

    for (int i = n ; i >= 0; i--){
        if(s[i] == 'W') {
            numw[i] += numw[i + 1] + 1;
        }else{
            numw[i] = numw[i + 1];
        }
    }

    for (int i = 1; i <= n; i++){
        if(s[i] == 'O'){
            ans += numc[i] * numw[i];
        }
    }

    cout << ans << endl;
    return 0;
}