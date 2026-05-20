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
    int preIdx = 0;
    int inIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit)
    {
        if(preIdx >= preorder.size()) return nullptr;
        if(inorder[inIdx] == limit)
        {
            inIdx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preIdx++]);
        node->left = dfs(preorder,inorder,node->val);
        node->right = dfs(preorder,inorder,limit);
        return node;
    }
};
