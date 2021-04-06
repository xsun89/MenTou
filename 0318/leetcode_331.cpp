//
// Created by Xin Sun on 2021-03-22.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tmp;
        for (int i = 0, j = 0; i < preorder.size() ; i = j + 1){
            j = i;
            while (j < preorder.size() && preorder[j] != ',') j++;
            tmp.push_back(preorder.substr(i, j - i));
            int last = tmp.size() - 1;
            while(tmp.size() >= 3 && tmp[last] == "#" && tmp[last -1] == "#"){
                tmp[last - 2] = "#";
                tmp.pop_back();
                tmp.pop_back();
                last = tmp.size() - 1;
            }
            if(tmp.size() == 2 && tmp[0] == "#" && tmp[1] == "#"){
                return false;
            }
        }
        return tmp.size() == 1 && tmp[0] == "#";
    }
};
int main()
{
    string t = "91,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution s;
    cout << s.isValidSerialization(t) << endl;
    return 0;
}
