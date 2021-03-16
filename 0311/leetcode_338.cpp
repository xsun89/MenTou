//
// Created by Xin Sun on 2021-03-15.
//
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1);
        ret[0] = 0;
        for (int i = 1; i <= num; i++){
            ret[i] = ret[i & (i -1)] + 1;
        }

        return ret;
    }
};
int main()
{
    return 0;
}
