//
// Created by sunxi on 2021-04-25.
//
#include <iostream>

using namespace std;

int n, ans;
int nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int func(int x)
{
    if(x == 0){
        return 6;
    }
    int t;
    while(x){
        t += nums[x % 10];
        x /= 10;
    }
    return t;
}

bool check(int a, int b){
    int c = a + b;
    return (func(c) + func(a) + func(b)) + 4 == n;
}
int main()
{
    cin >> n;
    for (int i = 0; i < 2000; i++){
        for (int j = 0; j < 2000; j++){
            if(check(i, j)){
                ans++;
                cout << i << "+" << j << "=" << i+j << endl;
            }
        }
    }

    cout << ans << endl;
    return 0;
}