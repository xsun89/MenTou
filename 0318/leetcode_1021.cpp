//
// Created by Xin Sun on 2021-03-20.
//
#include <iostream>

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int num = 0;
        for (int i = 0; i < S.size(); i++){
            if(S[i] == '(') {
                num++;
            };
            if(S[i] == ')') num--;

            if(num == 1 && S[i] == '('){
                S[i] = '*';
            }
            if(num == 0 && S[i] == ')'){
                S[i] = '*';
            }

        }
        S.erase(std::remove(S.begin(), S.end(), '*'), S.end());
        cout << S << endl;
    }
};
int main() {
    Solution s;
    string S = "(()())(())";
    s.removeOuterParentheses(S);
    return 0;
}
