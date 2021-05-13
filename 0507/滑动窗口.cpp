//
// Created by Xin Sun on 2021-05-12.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int getMaxIndex(vector<int> &nums, int i, int k){
        int maxIndex = i;
        for(int j = i - k + 1; j < i; ++j)
            if(nums[j] > nums[maxIndex]){
                maxIndex = j;
            }
        return maxIndex;
    }
    vector<int> maxSlidingWindow_guides(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        int maxInd = 0;
        for(int i = k - 1; i < nums.size(); i++){
            if(i - maxInd >= k - 1){
                maxInd = getMaxIndex(nums, i, k);
            }else if(nums[i] > nums[maxInd]){
                maxInd = i;
            }
            ans.push_back(nums[maxInd]);

        }

        return ans;
    }

    vector<int> maxSlidingWindow_priorityQueue(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0) return ans;

        priority_queue<pair<int, int>> q;
        for(int i = 0; i < k; i++){
            q.push(make_pair(nums[i], i));
        }
        ans.push_back(q.top().first);
        for(int i = k; i < nums.size(); i++){
            q.push(make_pair(nums[i], i));
            while(i - q.top().second >= k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }

    vector<int> maxSlidingWindow_dequeue(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(!que.empty() && nums[i] > nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            while(!que.empty() && i - que.front() >= k)
            {
                que.pop_front();
            }
            if(i >= k - 1) ans.push_back(nums[que.front()]);
        }
        return ans;
    }

};