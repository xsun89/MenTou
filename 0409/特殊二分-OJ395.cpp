//
// Created by Xin Sun on 2021-04-19.
//
#include <iostream>

using namespace std;

int n, m, nums[505], l, r;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        //l = max(l, nums[i]);
        r += nums[i];
    }

    while(l != r){
        int cnt = 0;
        int sum = 0;
        int mid = (l + r) / 2;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                cnt++;
            }else if(sum + nums[i] == mid){
                sum = 0;
                cnt++;
            }else{
                sum += nums[i];
            }
        }
        if(sum > 0){
            cnt++;
        }
        if(cnt <= m){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    int maxLength = l;
    int ans[m][2];
    int j = m;
    ans[m][1] = n;
    int sum = nums[n - 1];
    cout << maxLength << endl;
    for(int i = n - 2; i >= 0; i--){
        if(sum + nums[i] > maxLength){
            ans[j][0] = i + 2;
            sum = nums[i];
            j--;
            ans[j][1] = i + 1;
        }else if(sum + nums[i] == maxLength){
            ans[j][0] = i + 1;
            j--;
            sum = 0;
            ans[j][1] = i;
        }else{
            sum += nums[i];
        }
    }
    ans[1][0] = 1;
    for(int i = 1; i <= m; i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    cout << endl;
    return 0;
}
