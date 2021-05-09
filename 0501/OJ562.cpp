//
// Created by Xin Sun on 2021-05-04.
//
#include <iostream>
using namespace std;

int n, ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans << endl;
}
