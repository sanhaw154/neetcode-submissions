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
        queue< TreeNode* > Q;
        if(root != nullptr)
        {
            Q.push(root);
        }
        while(!Q.empty())
        {
            TreeNode* p = Q.front();
            Q.pop();
            if(p->left != nullptr)
            {
                Q.push(p->left);
            }
            if(p->right != nullptr)
            {
                Q.push(p->right);
            }

            TreeNode* tmp = p->right;
            p->right = p->left;
            p->left = tmp;

        }
        return root;
    }
};
