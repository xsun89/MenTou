//
// Created by sunxi on 2021-04-25.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n, nums[1005], ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums, nums + n);
    ans = 0;
    for(int i = n - 1; i >= 0; i -= 2){
        if(i == 0){
            ans += nums[i];
            break;
        }else if(i == 1){
            ans += nums[i];
            break;
        }else if(i == 2){
            ans += nums[0] + nums[1] + nums[2];
            break;
        }else{
            ans += min((nums[0] + nums[0] + nums[i] + nums[i - 1]), (nums[1] + nums[i] + nums[0] + nums[1]));
        }
    }

    cout << ans << endl;
    return 0;
}
