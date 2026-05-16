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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty())
        {   
            int size = q.size();
            if(!size) break;
            vector<int> list;
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* p = q.front();
                q.pop();
                if(p)
                {
                    if(p->left)q.push(p->left);
                    if(p->right)q.push(p->right);
                    list.push_back(p->val);
                }
            }
            res.push_back(list);
        }
        return res;
    }
};
