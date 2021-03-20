//
// Created by Xin Sun on 2021-03-15.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
class Solution__ {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (const auto& task : tasks) {
            mp[task]++;
        }

        priority_queue<int> pq;
        for (const auto& m : mp) {
            pq.push(m.second); // just care frequency, but not the task name
        }

        int cycle = n + 1;
        int res = 0;
        // Have to temporarily save the poped elements into a queue
        // so that two consectutive elements wouldn't be scheduled
        // together even it still has very high frequency
        while (!pq.empty()) {
            queue<int> q;
            int count = 0;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    q.push(pq.top());
                    pq.pop();
                    count++;
                }
            }

            while (!q.empty()) {
                auto freq = q.front();
                q.pop();
                freq--;
                if (freq > 0) {
                    pq.push(freq);
                }
            }

            // As long as pq is not empty, we have to add n + 1 cycles to res
            // it is possible that we didn't fully utilize the n + 1 cycles
            // meaning there could be CPU idle time
            // when pq is empty, meaning this is the last batch of tasks, we don't
            // have to wait full (n + 1) cycles if count < (n +1)
            res += pq.empty() ? count : cycle;
        }

        return res;
    }
};

class Solution_ {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> count;
        for (int i = 0; i < tasks.size(); i++){
            count[tasks[i]]++;
        }
        int taskNumber = tasks.size();
        vector<pair<char, int>> taskCnt;
        for (auto e : count) {
            taskCnt.push_back(make_pair(e.first, e.second));
        }
        sort(taskCnt.begin(), taskCnt.end(), [](const pair<char, int>a, const pair<char, int>b){
            return a.second > b.second;
        });

        int totalTaskCount = taskCnt[0].second;
        int maxCount = 0;
        for (int i = 0; i < taskCnt.size(); i++) {
            if(taskCnt[i].second == totalTaskCount){
                maxCount++;
            }
        }
        int ans = (totalTaskCount - 1) * (n + 1) + maxCount;
        ans = max(taskNumber, ans);
        return ans;
    }
};


class Solution_w {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> count;
        for (int i = 0; i < tasks.size(); i++){
            count[tasks[i]]++;
        }
        int taskNumber = tasks.size();

        vector<pair<char, int>> taskCnt;
        for (auto e : count) {
            taskCnt.push_back(make_pair(e.first, e.second));
        }
        sort(taskCnt.begin(), taskCnt.end(), [](const pair<char, int>a, const pair<char, int>b){
            return a.second > b.second;
        });

        int totalTaskCount = taskCnt[0].second;
        vector<char> ret;
        while(taskCnt.size() > 0){
            int j = taskCnt.size();
            for(int i = 0; i < n + 1; i++) {
                if(i < j && taskCnt.at(i).second > 0) {
                    ret.push_back(taskCnt.at(i).first);
                    taskCnt.at(i).second--;
                }else{
                    ret.push_back('*');
                }
            }
            vector<pair<char, int>>::iterator it = taskCnt.begin();
            while(it != taskCnt.end()){
                if(it->second == 0){
                    taskCnt.erase(it);
                }else{
                    it++;
                }
            }
        }
        while(ret.back() == '*'){
            ret.pop_back();
        }
        for (int i = 0; i < ret.size(); i++) {
            cout << ret.at(i) << endl;
        }
        return ret.size();
    }
};
class ComparisonClass {
public:
    bool operator() (const pair<char, int>a, const pair<char, int>b){
        return a.second < b.second;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> count;
        for (int i = 0; i < tasks.size(); i++){
            count[tasks[i]]++;
        }
        int taskNumber = tasks.size();

        vector<pair<char, int>> taskCnt;
        for (auto e : count) {
            taskCnt.push_back(make_pair(e.first, e.second));
        }
        sort(taskCnt.begin(), taskCnt.end(), [](const pair<char, int>a, const pair<char, int>b){
            return a.second > b.second;
        });

        priority_queue<pair<char, int>, vector<pair<char, int>>, ComparisonClass> pq(taskCnt.begin(),taskCnt.end());

        vector<char> ret;
        int cycle = n + 1;
        while (!pq.empty()) {
            queue<pair<char, int>> q;
            int count = 0;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    q.push(pq.top());
                    ret.push_back(pq.top().first);
                    pq.pop();
                    count++;
                }else{
                    ret.push_back('*');
                }
            }

            while (!q.empty()) {
                auto freq = q.front();
                q.pop();
                freq.second--;
                if (freq.second > 0) {
                    pq.push(freq);
                }
            }

            // As long as pq is not empty, we have to add n + 1 cycles to res
            // it is possible that we didn't fully utilize the n + 1 cycles
            // meaning there could be CPU idle time
            // when pq is empty, meaning this is the last batch of tasks, we don't
            // have to wait full (n + 1) cycles if count < (n +1)
            //res += pq.empty() ? count : cycle;

        }

        while(ret.back() < 'A' || ret.back() > 'Z'){
            ret.pop_back();
        }

        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << endl;
        }

        return ret.size();
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    cout << s.leastInterval(tasks, 2) << endl;
    return 0;
}
