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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int value = -1;
        dfs(root,k,value);
        return value;
    }
    void dfs(TreeNode* node,int& k ,int& value)
    {   
        if(!node) return;
        dfs(node->left,k,value);
        if(k == 0) return;
        k--;
        if(k == 0)
        {
            value = node->val;
            return;
        } 
        dfs(node->right,k,value);
    }
};
