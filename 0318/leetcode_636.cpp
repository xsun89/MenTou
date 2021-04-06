//
// Created by Xin Sun on 2021-03-22.
//
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> op;

        for (int i = 0, pre = 0; i < logs.size(); i++){
            int pos0 = 0;
            int pos1 = logs[i].find_first_of(":");
            int pos2 = logs[i].find_last_of(":");
            string id_ = logs[i].substr(pos0, pos1);
            int id = stoi(id_);
            string status = logs[i].substr(pos1 + 1, pos2 - pos1 -1);
            string time = logs[i].substr(pos2 + 1, logs[i].size());
            int exclusiveTime = stoi(time);
            if(!op.empty()) ans[op.top()] += exclusiveTime - pre + (status == "end");
            pre = exclusiveTime + (status == "end");
            if(status == "start"){
                op.push(id);
            }else{
                op.pop();
            }

        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> str;
    str.push_back("0:start:0");
    str.push_back("1:start:2");
    str.push_back("1:end:5");
    str.push_back("0:end:6");
    vector<int> ans = s.exclusiveTime(2, str);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}