//
// Created by Xin Sun on 2021-04-05.
//
#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode *getTreeNode(vector<int>& preorder, vector<int>& inorder,
                          unordered_map<int, int> &mp,
                          int preStart, int preEnd, int inStart, int inEnd){
        if(preStart >= preEnd || inStart >= inEnd) return nullptr;

        int rootIdx = mp.find(preorder[preStart])->second;
        int leftLength = rootIdx - mp.find(inorder.at(inStart))->second;
        int rightLength = mp.find(inorder.at(inEnd))->second - rootIdx;
        TreeNode node = TreeNode(inorder[rootIdx]);

        int newInLeftStart = rootIdx - leftLength;
        int newInLeftEnd = rootIdx;
        int newInRightStart = rootIdx + 1;
        int newInRightEnd = rootIdx + rightLength;
        int newPreLeftStart = preStart++;
        int newPreLeftEnd = newPreLeftStart + leftLength;
        int newPreRightStart = newPreLeftEnd + 1;
        int newPreRightEnd = newPreRightStart + rightLength;
        node.left = getTreeNode(preorder, inorder, mp, newInLeftStart, newInLeftEnd, newPreLeftStart, newPreLeftEnd);
        node.right = getTreeNode(preorder, inorder, mp, newInRightStart, newInRightEnd, newPreRightStart, newPreRightEnd);
        return &node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return nullptr;
        if(preorder.size() == 0) return nullptr;
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode *ans = getTreeNode(preorder, inorder, mp, 0, preorder.size() -1, 0, inorder.size() -1);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *node = s.buildTree(preorder, inorder);
    cout << " " << endl;
    return 0;
}
