//
// Created by Xin Sun on 2021-04-03.
// 剑指 Offer 32 - II. 从上到下打印二叉树 II
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_ {
    public:
    void getResult(TreeNode *root, int k, vector<vector<int>> &p){
        if(root == NULL) return;

        if(p.size() == k) p.push_back(vector<int>());
        p[k].push_back(root->val);
        k++;
        getResult(root->left, k, p);
        getResult(root->right, k, p);

        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        getResult(root, 0, ans);
        return ans;
    }

};
class Solution {
public:
    void __leverOrder(TreeNode *root, vector<vector<int>> &p){
        if(root == nullptr) return;
        queue<TreeNode *> queue;
        queue.push(root);

        while(!queue.empty()) {
            int n = queue.size();

            vector<int> *tmp = new vector<int>();
            p.push_back(*tmp);
            for(int i = 0; i < n; i++) {
                TreeNode *cur = queue.front();
                queue.pop();
                p.back().push_back(cur->val);
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push(cur->right);
                }
            }
        }

        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        __leverOrder(root, ans);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = nullptr;
    root->left->left = nullptr;
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution_ s;
    vector<vector<int>> p;
    p = s.levelOrder(root);
    cout << "end" << endl;
    return 0;
}
