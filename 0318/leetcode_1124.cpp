//
// Created by Xin Sun on 2021-03-23.
//
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution_ {
public:
    int longestWPI(vector<int> &hours) {
        vector<int> cnt;
        vector<int> cntSum;
        stack<int> danDiaoStack;
        int sum = 0;
        cntSum.push_back(0);
        danDiaoStack.push(0);
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= 8) {
                cnt.push_back(1);
            } else {
                cnt.push_back(-1);
            }
            sum += cnt[i];
            cntSum.push_back(sum);
        }
        //找出前缀和数组 cntSum 中两个索引 i 和 j，使 j - i 最大，且保证 cntSum[j] - cntSum[i] 大于
        //0
        //0。到此，我们就将这道题转化为，求 cntSum 数组中的一个最长的上坡，可以用单调栈实现。
        for (int i = 1; i <= cntSum.size() - 1; i++) {
            if (cntSum[i] < cntSum[danDiaoStack.top()]) {
                danDiaoStack.push(i);
            }
        }
        int ans = 0;
        for (int i = cntSum.size() - 1; i > 0; i--) {
            while (!danDiaoStack.empty() && cntSum[i] - cntSum[danDiaoStack.top()] > 0) {
                ans = max(ans, i - danDiaoStack.top());
                danDiaoStack.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:

    int longestWPI(vector<int> &hours) {
        unordered_map<int, int> ind;
        unordered_map<int, int> f;
        ind[0] = -1;
        f[0] = 0;
        int cnt = 0, ans = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8) cnt += 1; else cnt -= 1;
            if (ind.find(cnt) == ind.end()) {
                ind[cnt] = i;
                if (ind.find(cnt - 1) == ind.end()) f[cnt] = 0;
                else f[cnt] = f[cnt - 1] + (i - ind[cnt - 1]);
            }
            if (ind.find(cnt - 1) == ind.end()) continue;
            ans = max(ans, i - ind[cnt - 1] + f[cnt - 1]);

        }
        return ans;

    }

};

int main() {
    Solution s;
    vector<int> data = {9, 9, 6, 0, 6, 6, 9};
    cout << s.longestWPI(data) << endl;
    return 0;
}
