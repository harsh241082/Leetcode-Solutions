// LeetCode 257. Binary Tree Paths
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root)
            return ans;
        if (!root->left && !root->right)
        {
            ans.push_back(to_string(root->val));
            return ans;
        }
        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);
        for (string path : leftPaths)
        {
            ans.push_back(to_string(root->val) + "->" + path);
        }
        for (string path : rightPaths)
        {
            ans.push_back(to_string(root->val) + "->" + path);
        }
        return ans;
    }
};