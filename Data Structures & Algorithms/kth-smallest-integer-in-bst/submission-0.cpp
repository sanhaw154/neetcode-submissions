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
        int left_num = dfsFind(root->left);
        if( k == left_num + 1 )
        {
            return root->val;
        }
        else if( k < left_num + 1)
        {
            return kthSmallest(root->left, k);
        }
        else
        {
            return kthSmallest(root->right, k - left_num - 1);
        }
    }
    int dfsFind(TreeNode* root)
    {
        if(!root) return 0;
        return dfsFind(root->left) + dfsFind(root->right) + 1;
    }
};
