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
    int node_val_min = -1001;
    int node_val_MAX = 1001;
    bool isValidBST(TreeNode* root) 
    {
        return valid(root,node_val_min,node_val_MAX);
    }
    bool valid(TreeNode* node , int left , int right) //用數值range判斷該點的位置是否valid
    {
        if(!node) return true;
        if( left >= node->val || right <= node->val ) return false;
        else
        {
            return valid(node->left, left, node->val) && valid(node->right, node->val, right) ;
        }
    }
};
