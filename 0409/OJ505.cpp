//
// Created by sunxi on 2021-04-24.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int n;
string nums[100005];
bool cmp(const string &s1, const string &s2){
    return s1 + s1 > s2 + s1;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums, nums + n, cmp);
    string ans;
    for(int i = 0; i < n; i++){
        ans += nums[i];
    }

    cout << ans << endl;
    return 0;
}
