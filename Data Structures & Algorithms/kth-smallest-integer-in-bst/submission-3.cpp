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
        int cur_visit = 0;
        int value = -1;
        dfs(root,cur_visit,k,value);
        return value;
    }
    void dfs(TreeNode* node, int& cur_visit,int& k ,int& value)
    {   
        if(!node) return;
        dfs(node->left,cur_visit,k,value);
        if(cur_visit == k) return;
        cur_visit++;
        if(cur_visit == k)
        {
            value = node->val;
            return;
        } 
        dfs(node->right,cur_visit,k,value);
    }
};
