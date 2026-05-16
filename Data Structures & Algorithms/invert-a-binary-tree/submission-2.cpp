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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        if(root != nullptr) s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();
            if(p->left != nullptr) s.push(p->left);
            if(p->right != nullptr) s.push(p->right);
            swap(p->left,p->right);
        }
        return root;
    }
};
