//
// Created by Xin Sun on 2021-04-05.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
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
    void loadData(vector<vector<long long>> &data)
    {
        ifstream inFile;
        // open the file stream
        inFile.open("/Users/xsun/CLionProjects/Haizei/MenTou/0402/caidan.txt");
        // check if opening a file failed
        if (inFile.fail()) {
            cerr << "Error opeing a file" << endl;
            inFile.close();
            exit(1);
        }
        string line;
        long long value;
        int i = 0;
        while (getline(inFile, line)) {
            istringstream iss(line);
            if(data.size() == i){
                data.push_back(vector<long long>());
            }
            while(iss >> value){
                data[i].push_back(value);
            }
            i++;
        }
        inFile.close();
        return;
    }
    void postorderTraversal(TreeNode * root, vector<long long> &ret){
        if(root == nullptr){
            return;
        }
        postorderTraversal(root->left, ret);
        postorderTraversal(root->right, ret);
        ret.push_back(root->val);

        return;
    }
    TreeNode *getTreeNode(vector<long long>& preorder, vector<long long>& inorder){
        if(preorder.size() == 0) return nullptr;

        int pos = 0;
        while(inorder[pos] != preorder[0]) pos++;
        vector<long long> l_in, l_pre, r_in, r_pre;

        for(long long i = 0; i < pos; i++){
            l_in.push_back(inorder[i]);
            l_pre.push_back(preorder[i + 1]);
        }

        for(long long i = pos + 1; i < preorder.size(); i++){
            r_in.push_back(inorder[i]);
            r_pre.push_back(preorder[i]);
        }

        TreeNode *node = new TreeNode(inorder[pos]);


        node->left = getTreeNode(l_pre, l_in);
        node->right = getTreeNode(r_pre, r_in);
        return node;
    }
    TreeNode* buildTree(vector<long long>& preorder, vector<long long>& inorder) {
        if(preorder.size() != inorder.size()) return nullptr;
        if(preorder.size() == 0) return nullptr;
        TreeNode *ans = getTreeNode(preorder, inorder);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<long long>> data;
    s.loadData(data);
    vector<long long> preorder = data[0];
    vector<long long> inorder = data[1];
    TreeNode *node = s.buildTree(preorder, inorder);
    vector<long long> v;
    s.postorderTraversal(node, v);
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans += v.at(i) * (i + 1);

    }
    cout << ans << endl;
    return 0;
}
