//
// Created by Xin Sun on 2021-04-18.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000;
int  n, m, nums[MAX_N + 5], l, r;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums, nums + n);
    l = 1;
    r = nums[n - 1] - nums[0];
    while(r != l){
        int mid = (l + r + 1) >> 1;
        int cnt = 1;
        int left = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[left] >= mid){
                left = i;
                cnt++;
            }
        }

        if(cnt < m){
            r = mid - 1;
        }else{
            l = mid;
        }
    }

    cout << r << endl;
    return 0;
}
