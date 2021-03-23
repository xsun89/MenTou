//
// Created by Xin Sun on 2021-03-19.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        if(pushed.size() == 0) return true;
        stack<int> s;
        int i = 0, j = 0;
        while(i < pushed.size()) {
            s.push(pushed[i++]);
            while(!s.empty() && j < popped.size() && s.top() == popped[j]){
                j++;
                s.pop();
            }
        }
        for(; j < popped.size(); j++){
            if(s.top() == popped[j]){
                s.pop();
            }
        }
        if(s.empty()) {
            return true;
        }else{
            return false;
        }
    }
};

class Solution_ {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        if(pushed.size() == 0) return true;
        stack<int> s;

        for(int i = 0, j = 0; i < popped.size(); i++){
            while(j < pushed.size() && (s.empty() || s.top() != popped[i]))
            {
                s.push(pushed[j++]);
            }
            if(s.top() != popped[i]){
                return false;
            }
            s.pop();
        }
       return true;
    }
};
int main()
{
    Solution_ s;
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}
