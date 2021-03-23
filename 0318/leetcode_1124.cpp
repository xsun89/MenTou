//
// Created by Xin Sun on 2021-03-23.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> cnt;
        vector<int> cntSum;
        int sum = 0;
        for (int i = 0; i < hours.size(); i++){
            if(hours[i] >= 8){
                cnt.push_back(1);
            }else{
                cnt.push_back(-1);
            }
            sum += cnt[i];
            cntSum.push_back(sum);
        }
        for (int i = 0; i < cnt.size(); i++){
            cout << cnt[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < cntSum.size(); i++){
            cout << cntSum[i] << " ";
        }
        cout << endl;
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> data = {9,9,6,0,6,6,9};
    s.longestWPI(data);
    return 0;
}
