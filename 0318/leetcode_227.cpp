//
// Created by Xin Sun on 2021-03-22.
//
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    int level(char op){
        switch(op){
            case '@': return -1;
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
        }
        return 0;
    }
    int calc(int a, char op, int b){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }

        return 0;
    }
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        s += '@';
        for (int i = 0, n = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i] - '0');
                continue;
            }
            num.push(n);
            n = 0;
            while(!op.empty() && level(s[i]) <= level(op.top())){
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(calc(a, op.top(), b));
                op.pop();
            }

            op.push(s[i]);
        }

        return num.top();
    }
};

int main() {

    string str = "2048";
    Solution s;
    cout << s.calculate(str) << endl;
    return 0;
}