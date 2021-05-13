//
// Created by Xin Sun on 2021-05-11.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> dfs(int low, int high){
        if(low > high) return vector<TreeNode*>{nullptr};   // 表示只有一种可能：空树
        vector<TreeNode*> res;
        //尝试每个数字作为根节点
        for(int mid=low; mid<=high; ++mid) {
            auto lt = dfs(low,  mid-1);    // 左子树的所有可能
            auto rt = dfs(mid+1, high);    // 右子树的所有可能
            for(auto& left:lt) {
                for(auto& right:rt) {
                    // 左子树的所有情况 * 右子树的所有情况，即为此树的所有情况
                    res.push_back(new TreeNode(mid, left, right));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0) return ans;

        ans = dfs(1, n);

        return ans;
    }
};