//
// Created by sunxi on 2021-04-27.
//
#include <iostream>

using namespace std;
long long a, b, ans;

int main() {
    cin >> a >> b;

    for (int k = 3; k <= 17; k++) {
        for (int l = 1; l <= k; l++) { // l is special number index
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (l == 1 && i == 0) {
                        continue;
                    }
                    if (l != 1 && j == 0) {
                        continue;
                    }
                    long long t = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m == l) {
                            t = t * 10 + i;
                        } else {
                            t = t * 10 + j;
                        }
                    }
                    //cout << t << endl;
                    if (t >= a && t <= b) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
