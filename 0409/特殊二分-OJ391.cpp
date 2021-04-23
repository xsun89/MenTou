//
// Created by Xin Sun on 2021-04-17.
//
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 10000000;
long long m, n, l = 0, r = 0;
long long nums[MAX_N + 5];

int main()
{
    scanf("%lld%lld", &n, &m);
    for(long long i = 0; i < n; i++){
        scanf("%lld", &nums[i]);
        l = max(l, nums[i]);
        r += nums[i];
    }
    while(l != r){
        long long mid = (l + r) >> 1;
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                cnt++;
            }else if(sum + nums[i] == mid){
                cnt++;
                sum = 0;
            }else{
                sum += nums[i];
            }
        }
        if(sum > 0){
            cnt++;
        }
        if(cnt > m){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
