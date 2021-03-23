//
// Created by Xin Sun on 2021-03-20.
//
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++){
            switch (s[i]){
                case '(':{
                    pair<char, int> mp;
                    mp.first = s[i];
                    mp.second = i;
                    st.push(mp);
                    break;
                }
                case ')':{
                    if(st.empty() || st.top().first != '('){
                        s[i] = '*';
                    }else{
                        st.pop();
                    }
                    break;
                }
            }

        }
        while (!st.empty()){
            s[st.top().second] = '*';
            st.pop();
        }
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

int main()
{
    Solution s;
    string str = "a)b(c)d";
    s.minRemoveToMakeValid(str);
    return 0;
}