//
// Created by Xin Sun on 2021-03-15.
//
//有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
//
//示例 1:
//
//输入: k = 5
//
//输出: 9
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/get-kth-magic-number-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int getKthMagicNumber(int k){
        vector<int> arr;
        arr.push_back(1);
        int p3 = 0, p5 = 0, p7 = 0;
        int ans = 0;
        while(arr.size() < k){
            ans = arr[p3] * 3;
            ans = min(ans, arr[p5] * 5);
            ans = min(ans, arr[p7] * 7);
            if(ans == arr[p3] * 3){
                p3++;
            }
            if(ans == arr[p5] * 5){
                p5++;
            }
            if(ans == arr[p7] * 7){
                p7++;
            }
            arr.push_back(ans);
        }

        return arr[k - 1];
    }

};
int main()
{
    Solution s;
    int ret = s.getKthMagicNumber(3);
    cout << ret << endl;
    return 0;
}
