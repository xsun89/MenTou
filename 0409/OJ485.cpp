//
// Created by sunxi on 2021-04-24.
//

#include <iostream>

using namespace std;
int n, ans, nums[105], avg, sum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    avg = sum / n;
    for (int i = 0; i < n - 1; i++){
        int tmp = abs(avg - nums[i]);
        if(nums[i] < avg){
            nums[i] += tmp;
            nums[i + 1] -= tmp;
            ans++;
        }else if(nums[i] > avg){
            nums[i] -= tmp;
            nums[i + 1] += tmp;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}