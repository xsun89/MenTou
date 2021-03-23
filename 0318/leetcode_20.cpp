//
// Created by Xin Sun on 2021-03-20.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        if(s[0] == ']' || s[0] == '}' || s[0] == ')'){
            return false;
        }
        stack<char> stack;
        while(i < s.size()){
            if(s[i] == '{'){
                stack.push(s[i]);
            }
            if(s[i] == '['){
                stack.push(s[i]);
            }
            if(s[i] == '('){
                stack.push(s[i]);
            }
            if(s[i] == '}'){
                if(!stack.empty() && stack.top() == '{'){
                    stack.pop();
                }else{
                    return false;
                }
            }
            if(s[i] == ']'){
                if(!stack.empty() && stack.top() == '['){
                    stack.pop();
                }else{
                    return false;
                }
            }
            if(s[i] == ')'){
                if(!stack.empty() && stack.top() == '('){
                    stack.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    return 0;
}