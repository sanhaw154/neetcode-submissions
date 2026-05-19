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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>>q;
        if(!root) return true;
        q.push({ root, node_val_min, node_val_MAX });
        while(!q.empty())
        {
            auto& [ node, low, high]= q.front();
            if(!node) continue;
            if(node->val <= low || node->val >= high )
            {
                return false;
            }
            if(node->left) q.push({node->left, low, node->val});
            if(node->right) q.push({node->right, node->val, high});
            q.pop();
        }
        return true;
    }
};
