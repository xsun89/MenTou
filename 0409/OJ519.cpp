//
// Created by sunxi on 2021-04-27.
//
#include <iostream>

using namespace std;
int a, b, ans;
int main()
{
    cin >> a >> b;
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            if(i == j){
                continue;
            }
            for (int k = 3; k <= 17; k++){
                for (int l = 1; l <= k; l++){
                    if(l == 1 && i == 0){
                        continue;
                    }
                    if(l != 1 && j == 0){
                        break;
                    }
                    long long t;
                    for (int m = 1; m <= k; m++){
                        if(m == l) {
                            t = t * 10 + i;
                        }else{
                            t = t * 10 + j;
                        }
                        //if(t >= a && t <= b) {
                            ans++;
                        //}
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
