//
// Created by Xin Sun on 2021-04-18.
//

#include <iostream>
#include <iomanip>

using namespace std;
double nums[10005], l, r;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        r = max(r, nums[i]);
    }
    l = 0.0;
    while(r - l > 0.00001){
        double mid = (l + r) / 2.0;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += nums[i] / mid;
        }
        if(cnt >= m){
            l = mid;
        }else{
            r = mid;
        }
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << r - 0.005<< endl;
    return 0;
}